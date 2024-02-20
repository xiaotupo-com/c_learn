#include "utils.h"
#include <stdio.h>

void print_array_int(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == (size - 1))
		{
			printf("%d\n", *(arr++));
		}
		else {
			printf("%d, ", *(arr++));
		}
	}
}