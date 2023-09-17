#include "sort.h"
#include "utils.h"
#include <stdio.h>

/**
 * @brief ð������
 * @param arr �����ַ
 * @param len ���������С
 * @return sort_count �����ñȽϵĴ���
*/
int bubble_sort(int* arr, int len)
{
	int i, j, temp;
	int sort_count = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sort_count++;
			}
		}
	}

	return sort_count;
}


/**
 * @brief ð������Ĳ��Ժ���
 * @param  none
 * @return none
*/
void bubble_sort_test(void)
{
	int sort_number = 0;
	// ���������������վ��https://www.lddgo.net/string/randomnumber
	int arrayi[] = { 5, 3, 2, 1, 4, 8, 7, 9, 0, 6 };
	int array_size = sizeof(arrayi) / sizeof(int);
	printf("ԭʼ���飺\n");
	print_array_int(arrayi, array_size);

	sort_number = bubble_sort(arrayi, array_size);
	printf("���������飺\n");
	print_array_int(arrayi, array_size);
	printf("sort number: %d\n", sort_number);

}

/**
* @brief ѡ������ { 4, 2, 6, 1, 3, 8, 9, 7, 0, 5}
* @param arr: �����ַ
* @param size: ����Ĵ�С
* @return	sort_number �����õıȽϴ���
*/
int selection_sort(int* arr, int size)
{
	int i, j, temp;
	int sort_number = 0;
	for (i = 0; i < size - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < size; j++)
		{
			// ��� arr[j] С�� arr[min] ����� min ��������������С��ֵ
			if (arr[j] < arr[min])
			{
				min = j; // �� min ������Сֵ
			}
			sort_number++;
		}

		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}

	return sort_number;
}

/**
 * @brief ѡ��������Ժ���
 * @param  none
 * @return none
*/
void selection_sort_test(void)
{
	int arrayi[] = { 4, 2, 6, 1, 3, 8, 9, 7, 0, 5 };
	int array_size = sizeof(arrayi) / sizeof(int);
	int sort_number = 0;
	printf("����ǰ��\n");
	print_array_int(arrayi, array_size);
	sort_number = selection_sort(arrayi, array_size);
	printf("�����\n");
	print_array_int(arrayi, array_size);
	printf("sort number: %d\n", sort_number);
}

/**
* @brief ��������
* @param arr: Ҫ���������
* @param size: Ҫ��������Ĵ�С
* @return ����ѭ���Ĵ���
*/
int insert_sort(int* arr, int size)
{
	int a = 0;
	int i, j;
	int temp;
	// i ����δ���������
	// j ���������������
	// { 1,8,3,4,2,9 }
	for (i = 1; i < size; i++)
	{
		temp = arr[i]; // ��ȡ��i��Ԫ�ص�ֵ
		// j = i������ѭ��һ�� j--������δ j>0 ���� jǰ���һ��ֵҪ���ڵ�ǰֵ temp
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1]; // ��� for �����������򽻻� j �� jǰ��һ��ֵ
		}
		arr[j] = temp;
	}
}

/**
 * @brief ����������Ժ���
 * @param  none
 * @return none
*/
void insert_sort_test(void)
{
	int arrayi[] = { 1,8,3,4,2,9 };
	int arr_size = sizeof(arrayi) / sizeof(int);
	Line("��������test");
	print_array_int(arrayi, arr_size);
	insert_sort(arrayi, arr_size);
	print_array_int(arrayi, arr_size);
}