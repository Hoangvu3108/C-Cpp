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
void tinhtoan(void(*ptr)(int,int),int a,int b)
{
    printf("Thuc hien phep toan:\n");
    ptr(a,b);
}
int main ()
{
    tinhtoan(&tong,31,8);
    return 0;
}