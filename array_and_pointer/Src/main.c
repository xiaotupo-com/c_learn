#include <stdio.h>
#include <string.h>

#define OLED_WIDTH	128
#define OLED_HEIGHT 64

#define OLED_BUFFER_SIZE	(OLED_WIDTH * OLED_HEIGHT / 8) 

typedef unsigned char u8;
typedef unsigned int u32;

u8 OLED_BUFFER[OLED_BUFFER_SIZE];

#define OUT_BR()	printf("\n")

/**
  * printf ��ӡ u8 ���͵�����
  * param arr: ָ�����������arr[i])
  * param size: �����С��Ҫ�������Ԫ��
  *
*/
void print_array_u8(u8* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *(arr++));
	}
	OUT_BR();
}

void array_print(void)
{
	u8 a[10] = { 0,1,2,3,4,5,6,7,8,9 };

	print_array_u8(&a[3], 2); // �����3 4
}

void sprintf_demo(void)
{
	// sprintf() ��ʽ��
	// ��Ҫ���� stdio.h �ļ�
	// ����ԭ�ͣ�int sprintf(char *str, const char *format, [argument,...]);
	char str[30];
	double a = 123.123456;
	double b = 90.12;
	sprintf(str, "a: %.2f\n", a);
	printf("%s\n", str);

	sprintf(str, "a: %.2f------b: %6.2f\n", a, b);
	printf("%s\n", str);
}

void sprintf_s_demo(void)
{
	// ��Ҫ���� stdio.h �ļ�
	// ����ԭ�ͣ�sprintf_s(char *const _Buffer, const size_t 
	// _BufferCount, const char *const _Format, ...);
#define STR_LEN 30
	char str[STR_LEN];

	double a = 123.123456;
	double b = 90.12;
	sprintf_s(str, STR_LEN, "a: %.2f\n", a);
	printf("%s\n", str);

	// �Ѹ�ʽ�����ݷŵ������ı�����
	char str_format[] = "a: %.2f------b: %6.2f\n";

	int str_len = sizeof(str_format);
	if (str_len < STR_LEN)
	{
		sprintf_s(str, sizeof(str), str_format, a, b);
	}
	printf("%s\n", str);
}



int main(void)
{
	// ����һ�����鲢��ʼ��
	u8 array_buf[10] = { 0,1,2,3,4,5,6,7,8,9 };
	// ��ȡ����ĳ���
	int len = sizeof(array_buf) / sizeof(u8);

	// ����һ��ָ�������ָ��
	u8* arrayp = array_buf;

	printf("��ʽ1��\n");
	// ������ӡ���鷽ʽ1
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arrayp++));
	}
	OUT_BR();

	arrayp = array_buf; // �� arrapy ����ָ�� array_buf[0]
	// ������ӡ���鷽ʽ2
	printf("��ʽ2��\n");
	for (u8 i = 0; i < len; i++)
	{
		printf("%d ", *(arrayp + i));
	}
	OUT_BR();

	// ������ӡ���鷽ʽ3
	printf("��ʽ3��\n");
	for (u8 i = 0; i < len; i++)
	{
		printf("%d ", arrayp[i]);
	}
	OUT_BR();

	// ͨ��������
	printf("%d\n", *(array_buf + 2));

	/*
	��������帳ֵ��Ҫ�� memcpy() �������� string.h ͷ�ļ���
	*/
	u8 arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	u8 arr2[10];
	memcpy(arr2, arr1, 10);
	print_array_u8(arr1, 10);
	print_array_u8(arr2, 10);


	// ������ʽ������
	int a = 123, b = 123456;
	printf("%5d\n", a);		// Ĭ���Ҷ��룬����5λ������������ʹ�ÿո��滻
	printf("%05d\n", a);	// Ĭ���Ҷ��룬����5λ������������ʹ��0�滻
	printf("%-5d\n", a);	// ����룬����5λ������������ʹ�ÿո��滻
	printf("%-05d\n", a);	// ����룬����5λ������������ʹ�ÿո��滻
	printf("%5d\n", b);		// ����5λȫ�����

	// С����ʽ��
	double af = 123.326, bf = 90.12;
	printf("%.2f\n", af); // ��� 123.33
	printf("%.3f\n", bf); // ��� 90.120

	printf("%4.2f\n", bf); // ��� 90.12
	printf("%7.2f\n", bf); // ��� �ո�ո�90.12, 9ǰ�������ո�

	// �ַ������ʽ��
	char str[30] = "hello,world";
	char s1[5] = { 'a', 'b', 'c' };

	printf("%s==\n", s1);		// �����"abc=="
	printf("%2s==\n", s1);		// �����"abc=="
	printf("%5s==\n", s1);		// �����"  abc==" ���󲹿ո�
	printf("%-5s==\n", s1);		// �����"abc  " ���Ҳ��ո�

	printf("%4.2s==\n", s1);	// �����"  ab==" ���󲹿ո�
	printf("%.2s==\n", s1);		// �����"ab=="

	printf("%4.2s\n", str);		// �����"  he" ���󲹿ո�

	// sprintf() ��ʽ��
	sprintf_demo();

	// spirntf_s() ��ʽ��
	sprintf_s_demo();

	// array_print() 
	array_print();
}