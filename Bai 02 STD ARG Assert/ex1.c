
#include <stdio.h>
#include <stdarg.h>

void display(int count, ... ){
    va_list va;
    va_start(va, count);

    for (int i=0;i<count;i++)
    {
        printf("Value at %d: %d\n",i,va_arg(va,int));
    }
    va_end(va);
}
int main ()
{
    display(5,6,8,11,20,03);
    return 0;
}