#include "fibonacci.h"

#include <stdlib.h>
#include <string.h>
#include "utils.h"

void fibonacci_to_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0) {
			*arr = 1;
		}
		else if (i == 1) {
			*(arr + 1) = 1;
		}
		else {
			*(arr + i) = (*(arr + (i - 1))) + (*(arr + (i - 2)));
		}
	}
}

void fibonacci_to_array_test(void)
{
	printf("// 悲波那契数列\n");
#define array_size 100
	int* arrayi = malloc(sizeof(int) * array_size);
	if (arrayi) {
		memset(arrayi, 0, array_size);
		fibonacci_to_array(arrayi, array_size);
		print_array_int(arrayi, array_size);
	}
	free(arrayi); // 释放堆栈
}