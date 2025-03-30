#include<stdio.h>

int main ()
{
    int i=0;
    start: 
    if (i>=10)
    {
        goto end;
    }
    printf("%d\n",i);
    i++;
    goto start;
    end:
    printf("End of the program");
    return 0;
}