#include<stdio.h>

int main ()
{
    const int a = 5;
    int *p =(void*) &a;
    *p = 7;
    printf("%d", a);
}