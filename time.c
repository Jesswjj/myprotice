#include <stdio.h>
#include <time.h>


int main()
{
    time_t t, b;
    t = time(NULL);
    printf("The number t of seconds %ld\n",t);
    time(&b);
    printf("The number b of seconds %ld\n",b);
    char *s = ctime(&b);
    printf("the date is:%s\n", s);
}
