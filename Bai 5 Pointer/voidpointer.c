#include <stdio.h>

void tong (int a, int b)
{
    printf("Tong hai so %d và %d la %d\n", a, b, a + b);
}
int main ()
{
    int a =4;
    
    char c='H';

    double h= 11.3;

    void *ptr =&a;

    printf("Gia tri cua bien : %p\n", ptr);
    printf("Gia tri cua bien : %d\n", *(int*)ptr);
    ptr =&c;
    printf("Gia tri cua bien : %p\n", ptr);
    printf("Gia tri cua bien : %c\n", *(char*)ptr);
    ptr =&h;
    printf("Gia tri cua bien : %p\n",   ptr);
    printf("Gia tri cua bien : %f\n", *(double*)ptr);
    ptr =&tong;
    printf("Gia tri cua bien : %p\n", ptr);
    
    ((void (*)(int , int ))ptr)(9,4);

    
}
 

