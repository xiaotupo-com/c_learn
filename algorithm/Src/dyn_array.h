/**
 * @File 			dyn_array.h
 * @Version			V1.0
 * @Description		动态数组头文件
 * @Author			小土坡
 * @Email			xiaotupo@163.com
 * @Date            2023-9-7
 * @github			https://github.com/xiaotupo-com
*/

struct Dyn_arry_t
{
	int* array;
	int capacity;
	int size;
};


void dyn_array_test(void);
struct Dyn_arry_t dyn_array_init(int* array, int size);