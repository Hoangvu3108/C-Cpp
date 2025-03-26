#include<stdio.h>

    const int a = 10; 
    char *arr1 = "Hello";

int main()
{   
    // a = 20;                  // ở đây sẽ báo lỗi vì a là hằng số và không được phép thay đổi 
    // arr[1]='a';
    printf("%d", a);
    printf("%s", arr1);

}