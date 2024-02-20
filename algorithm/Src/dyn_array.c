#include "dyn_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "sort.h"

/**
 * @brief ��ʼ����̬����
 * @param array ��Ҫ��ʼ��������
 * @param size ������Ĵ�С
 * @return ���� my_array, һ�� Dyn_array
*/
struct Dyn_arry_t dyn_array_init(int* array, int size)
{
	// �ȴ���һ����ջ��������Ϊ��ʼ��̬���������
	int* temp = malloc(sizeof(int) * size * 2);

	if (temp)
	{
		/*for (size_t i = 0; i < size; i++)
		{
			temp[i] = array[i];
		}*/
		memcpy(temp, array, sizeof(int) * size);
		// ���ﲻ��ʹ�� memcpy ������ array �� temp��������array ֻ��һ��ָ��
	}

	struct Dyn_arry_t my_array;
	my_array.array = temp;
	my_array.capacity = size * 2;
	my_array.size = size;

	return my_array;
}

void dyn_array_insert(struct Dyn_arry_t* array, int var)
{
	if ((array->size) < (array->capacity))
	{
		
		array->array[array->size] = var;
		array->size++;
	}
	else
	{
		printf("�ѿռ�������\n");
		int* temp = malloc(sizeof(int) * array->capacity * 2);
		
		if (temp)
		{
			array->capacity = array->capacity * 2;
			memcpy(temp, array->array, sizeof(int) * array->size);
			array->array = temp;
			array->array[array->size] = var;
			array->size++;
		}
	}
}

/**
 * @brief	��̬������Ժ���
 * @param	none
 * @return	none
*/
void dyn_array_test(void)
{
	Line("��̬�������");
	struct Dyn_arry_t darray;
	//int iarray[5] = { 1,2,3,4,5 };
	darray = dyn_array_init((int[]) { 1, 2, 3, 4, 5 }, 5);
	printf("��̬�������\n");
	print_array_int(darray.array, darray.size); // ��ӡ����
	for (int i = 40; i > 0; i--)
	{
		dyn_array_insert(&darray, i - 6);
	}
	printf("capacity:%d\n", darray.capacity);
	print_array_int(darray.array, darray.size); // ��ӡ����
	
	free(darray.array); // �ͷŶ��ڴ�
}