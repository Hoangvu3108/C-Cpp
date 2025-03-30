// #include<stdio.h>
 
//  extern int count;
//  extern void display();
// int main(int argc, char const *argv[])
// {
//     display();
//     count = 20;
//     printf("count = %d\n",count);
//     display();
//     return 0;
// }
// # 1 "bai1.c" 2

//bai nay test dia chi cuar mang 2 chieu
#include <stdio.h>

int main() {
    int  arr[3][4];

    printf("Địa chỉ của mảng: %p\n", (int*)arr);
    printf("Địa chỉ của hàng đầu tiên: %p\n", (int*)arr[0]);
    printf("Địa chỉ của phần tử đầu tiên: %p\n", (int*)&arr[0][0]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Địa chỉ của phần tử arr[%d][%d]: %p\n", i, j, (int*)&arr[i][j]);
        }
    }

    return 0;
}

