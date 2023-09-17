#include "sort.h"
#include "utils.h"
#include <stdio.h>

/**
 * @brief 冒泡排序
 * @param arr 数组地址
 * @param len 传入数组大小
 * @return sort_count 排序用比较的次数
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
 * @brief 冒泡排序的测试函数
 * @param  none
 * @return none
*/
void bubble_sort_test(void)
{
	int sort_number = 0;
	// 在线随机数生成网站：https://www.lddgo.net/string/randomnumber
	int arrayi[] = { 5, 3, 2, 1, 4, 8, 7, 9, 0, 6 };
	int array_size = sizeof(arrayi) / sizeof(int);
	printf("原始数组：\n");
	print_array_int(arrayi, array_size);

	sort_number = bubble_sort(arrayi, array_size);
	printf("排序后的数组：\n");
	print_array_int(arrayi, array_size);
	printf("sort number: %d\n", sort_number);

}

/**
* @brief 选择排序 { 4, 2, 6, 1, 3, 8, 9, 7, 0, 5}
* @param arr: 数组地址
* @param size: 数组的大小
* @return	sort_number 排序用的比较次数
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
			// 如果 arr[j] 小于 arr[min] 则代表 min 的索引并不是最小的值
			if (arr[j] < arr[min])
			{
				min = j; // 让 min 等于最小值
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
 * @brief 选择排序测试函数
 * @param  none
 * @return none
*/
void selection_sort_test(void)
{
	int arrayi[] = { 4, 2, 6, 1, 3, 8, 9, 7, 0, 5 };
	int array_size = sizeof(arrayi) / sizeof(int);
	int sort_number = 0;
	printf("排序前：\n");
	print_array_int(arrayi, array_size);
	sort_number = selection_sort(arrayi, array_size);
	printf("排序后：\n");
	print_array_int(arrayi, array_size);
	printf("sort number: %d\n", sort_number);
}

/**
* @brief 插入排序
* @param arr: 要排序的数组
* @param size: 要排序数组的大小
* @return 排序循环的次数
*/
int insert_sort(int* arr, int size)
{
	int a = 0;
	int i, j;
	int temp;
	// i 代表未排序的索引
	// j 代表已排序的索引
	// { 1,8,3,4,2,9 }
	for (i = 1; i < size; i++)
	{
		temp = arr[i]; // 获取第i个元素的值
		// j = i，并且循环一次 j--，条件未 j>0 并且 j前面的一个值要大于当前值 temp
		for (j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1]; // 如果 for 条件成立，则交换 j 和 j前的一个值
		}
		arr[j] = temp;
	}
}

/**
 * @brief 插入排序测试函数
 * @param  none
 * @return none
*/
void insert_sort_test(void)
{
	int arrayi[] = { 1,8,3,4,2,9 };
	int arr_size = sizeof(arrayi) / sizeof(int);
	Line("插入排序test");
	print_array_int(arrayi, arr_size);
	insert_sort(arrayi, arr_size);
	print_array_int(arrayi, arr_size);
}