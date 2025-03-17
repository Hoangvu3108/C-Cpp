#include<stdio.h>

#define MAX 100
int main() {
    printf("Value of MAX is: %d\n", MAX);
    // Bỏ định nghĩa của MAX
    #undef MAX
    // định nghĩa lại giá trị của MAX
    #define MAX 200
    printf("Value of MAX after defining là: %d\n", MAX);
    return 0;
}