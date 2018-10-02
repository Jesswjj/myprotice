#include <stdio.h>
#include <string.h>

void showchar(const char* str)
{
    printf("get %d b, show %s\n", sizeof(*str), str);
}

int main(int argc, char** argv)
{
    char str[20];
    while(1)
    {
        printf("please input <20 words:");
        gets(str);
        showchar(str);
    }

    return 0;
}
