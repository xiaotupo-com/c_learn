#include "string_demo.h"
#include <stdio.h>
#include <string.h>

void string_test(void)
{
    char s[100];
#if 0
    if (gets(s) != NULL) {
        printf("%s\n", s);
    }
#endif

#if 0
    printf("请输入一些字符串：\n>>>");
    fgets(s, sizeof(s), stdin);
    printf("%s\n", s);

#endif

    // puts(">>> Hello,World!");

#if 0
    fputs(">>> Hello,World!", stdout);
#endif

#if 0
    puts("请输入一些内容：");
    fputs(">>> ", stdout);
    fgets(s, sizeof(s), stdin);
    printf(">>> %d\n", strlen(s)); // 获取字符串的长度
#endif

#if 0
    strcpy(s, "hello");

    printf(">>> %s\n", s);
#endif

#if 0
    char s2[] = "hello,wor";
    strncpy(s, s2, 5);
    printf(">>> %s\n", s);
#endif

#if 0
    strcat(s, "hello");
    strcat(s, ", world");
    printf(">>> %s\n", s);
#endif

#if 0
    int n = strcmp("hello", "world");
    if (n == 0)
    {
        printf("相等...\n");
    } else if(n > 0)
    {
        printf("s1大于s2...\n");
    } else {
        printf("s1小于s2...\n");
    }
#endif

#if 0
    int x = 10;
    int y = 20;
    int len = sprintf(s, "x: %d\ny: %d\n", x, y);
    printf("len: %d\n", len);
    puts(s);
#endif

#if 0
    char src[] = "张三 15";
    char name[20];
    int age;
    sscanf(src, "%s%d", name, &age);
    printf("%s\n", name);
    printf("%d\n", age);
#endif

#if 0
    char src[] = "hello123_world%你好";
    char* new_src = strchr(src, '1');
    printf("new_src: %s\n", new_src);
#endif

    char src1[] = "hello123_world%你好";
    char src2[] = "o12";
    char* new_src = strstr(src1, src2);
    printf("new_src: %s\n", new_src);


}
