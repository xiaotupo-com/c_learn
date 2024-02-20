#ifndef __MACRO_DEMO_H
#define __MACRO_DEMO_H

#define BR() printf("\n")

#define A(x) #x
#define B(a,b) #a"."#b
#define PI 3.1415926
#define ADD(n1,n2) ((n1) + (n2))
#define SQRT(n) ((n) * (n))

#define PRIVATE_MESSAGE(msg) do {\
    printf("===============%s===============\n", msg);\
} while(0)

#define TEST(x) test##x

void macro_test(void);

#endif // !__MACRO_DEMO_H
