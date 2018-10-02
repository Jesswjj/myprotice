#include <stdio.h>

void charcopy(char *des, const char *src)
{
    des = (char*)malloc(strlen(src)+1);
    while(*src != '\0')
    {
        *des = *src;
        des++;
        src++;
    }
    *des = '\0';

}

void str_copy(char *str1, char *str2)  // 字符串复制函数

{

    while(*str1++ = *str2++);  // 将字符串str2中的每个字符逐个复制到str1中，直到遇到字符串结束字符'\0'

}

void main()

{

    char s1[] = "abcd";

    char s2[5];

    //str_copy(s2, s1);  // 将字符串s1复制到s2中
    charcopy(s2, s1);
    printf("%s", s2);  // 输出字符串s2，输出结果为abcd

}
