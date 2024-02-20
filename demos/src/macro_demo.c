#include <stdio.h>
#include "macro_demo.h"

static void testA(void)
{
    printf("testA...\n");
}

static void system_macro_demo(void)
{
    printf("DATE: %s\n", __DATE__);
    printf("TIME: %s\n", __TIME__);
    printf("FILE: %s\n", __FILE__);
    printf("LINE: %d\n", __LINE__);
    printf("FUNC: %s\n", __func__);
}

void macro_test(void)
{
    printf("%s\n", B(12,23)); // 宏中的 # 的演示
    printf("%s\n", A(Hello));

    // 宏中的 ## 演示
    TEST(A)();

    int a = 10;
    int b = 20;

    int c = ADD(a,b);
    int d = SQRT(a);
    printf("c=%d\nd=%d\n", c, d);

    PRIVATE_MESSAGE("PRIVATE MESSAGE");
    system_macro_demo();
    PRIVATE_MESSAGE("系统宏");
}