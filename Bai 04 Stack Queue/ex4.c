#include<stdio.h>
#include<stdint.h>

int giaithua(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else 
    {
        return n * giaithua(n-1);
    }
}
int main ()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);

    if (n<0)
    {
        printf("Error");
    }
    else
    {
        printf("Giai thua cua %d la: %d",n,giaithua(n));
    }
}