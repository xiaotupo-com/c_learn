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
  * printf 打印 u8 类型的数组
  * param arr: 指针或（数组名，arr[i])
  * param size: 数组大小或要输出几个元素
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

	print_array_u8(&a[3], 2); // 输出：3 4
}

void sprintf_demo(void)
{
	// sprintf() 格式化
	// 需要包含 stdio.h 文件
	// 函数原型：int sprintf(char *str, const char *format, [argument,...]);
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
	// 需要包含 stdio.h 文件
	// 函数原型：sprintf_s(char *const _Buffer, const size_t 
	// _BufferCount, const char *const _Format, ...);
#define STR_LEN 30
	char str[STR_LEN];

	double a = 123.123456;
	double b = 90.12;
	sprintf_s(str, STR_LEN, "a: %.2f\n", a);
	printf("%s\n", str);

	// 把格式化内容放到单独的变量中
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
	// 定义一个数组并初始化
	u8 array_buf[10] = { 0,1,2,3,4,5,6,7,8,9 };
	// 获取数组的长度
	int len = sizeof(array_buf) / sizeof(u8);

	// 定义一个指向数组的指针
	u8* arrayp = array_buf;

	printf("方式1：\n");
	// 遍历打印数组方式1
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arrayp++));
	}
	OUT_BR();

	arrayp = array_buf; // 让 arrapy 重新指向 array_buf[0]
	// 遍历打印数组方式2
	printf("方式2：\n");
	for (u8 i = 0; i < len; i++)
	{
		printf("%d ", *(arrayp + i));
	}
	OUT_BR();

	// 遍历打印数组方式3
	printf("方式3：\n");
	for (u8 i = 0; i < len; i++)
	{
		printf("%d ", arrayp[i]);
	}
	OUT_BR();

	// 通过数组名
	printf("%d\n", *(array_buf + 2));

	/*
	数组的整体赋值，要用 memcpy() 函数，在 string.h 头文件中
	*/
	u8 arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	u8 arr2[10];
	memcpy(arr2, arr1, 10);
	print_array_u8(arr1, 10);
	print_array_u8(arr2, 10);


	// 整数格式化对齐
	int a = 123, b = 123456;
	printf("%5d\n", a);		// 默认右对齐，最少5位整数，不够的使用空格替换
	printf("%05d\n", a);	// 默认右对齐，最少5位整数，不够的使用0替换
	printf("%-5d\n", a);	// 左对齐，最少5位整数，不够的使用空格替换
	printf("%-05d\n", a);	// 左对齐，最少5位整数，不够的使用空格替换
	printf("%5d\n", b);		// 超过5位全部输出

	// 小数格式化
	double af = 123.326, bf = 90.12;
	printf("%.2f\n", af); // 输出 123.33
	printf("%.3f\n", bf); // 输出 90.120

	printf("%4.2f\n", bf); // 输出 90.12
	printf("%7.2f\n", bf); // 输出 空格空格90.12, 9前面两个空格

	// 字符数组格式化
	char str[30] = "hello,world";
	char s1[5] = { 'a', 'b', 'c' };

	printf("%s==\n", s1);		// 输出："abc=="
	printf("%2s==\n", s1);		// 输出："abc=="
	printf("%5s==\n", s1);		// 输出："  abc==" 从左补空格
	printf("%-5s==\n", s1);		// 输出："abc  " 从右补空格

	printf("%4.2s==\n", s1);	// 输出："  ab==" 从左补空格
	printf("%.2s==\n", s1);		// 输出："ab=="

	printf("%4.2s\n", str);		// 输出："  he" 从左补空格

	// sprintf() 格式化
	sprintf_demo();

	// spirntf_s() 格式化
	sprintf_s_demo();

	// array_print() 
	array_print();
}