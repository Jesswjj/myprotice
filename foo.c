#include <stdio.h>
#include <stdlib.h>

static int j;
int k = 0;
int func1(void)
{
    static int i = 0;
    i++;
    return i;
}

int func2(void)
{
    j = 0;
    j++;
    return j;
}
void fun(int b[100])
{
    printf("sizeof (b) = %d\n", sizeof(b));
}
int main()
{
//    int x, y;
//    for(k = 0; k < 10; k++)
//    {
//        x = func1();
//        y = func2();
//    }
//    printf("%d, %d", x, y);

    short *p = NULL;
    printf("sizeof (p) = %d\n", sizeof(p));
    printf("sizeof (*p) = %d\n", sizeof(*p));

    int a[100];

    printf("sizeof (a) = %d\n", sizeof(a));
    printf("sizeof (a[100]) = %d\n", sizeof(a[100]));


    printf("sizeof (&a) = %d\n", sizeof(&a));
    printf("sizeof (&a[0]) = %d\n", sizeof(&a[0]));

    int b[100];

    fun(b[100]);
    return 0;
}

int foo()
{
    char string[10], str1[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        str1[i] = 'a';
    }
    strcpy(string, str1);
    printf("%s", string);
}
