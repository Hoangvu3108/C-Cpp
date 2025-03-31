#include<stdio.h>
#include<assert.h>

void tong(int a,int b)
{
    printf("Tong  cua 2 so %d va %d  la: %d\n",a,b,a+b);
}
void hieu (int a, int b)
{
    printf("Hieu cua 2 so %d va %d la: %d\n",a,b,a-b);
}
void tich(int a, int b)
{
    printf("Tich cua 2 so %d va %d la: %d\n",a,b,a*b);
}
void thuong(int a ,int b)
{
    assert (b!=0);
    printf("Thuong cua 2 so %d va %d la: %f \n",a,b,(double)a/b);
}

int main (int argc, char const *argv[])
{
    // void (*ptr)(int,int);
    // ptr = &hieu;
    // ptr(2,3);
    // int (*test)(int a,int b );
    // test = &tich;
    // printf("Tich cua 2 so la: %d\n", test(3, 6));
    // return 0;
    void (*array[4])(int, int ) = {&tong, &hieu, &tich, &thuong};
    array[0](2,3);
    array[1](2,3);
    array[2](2,3);
    array[3](2,3);
}