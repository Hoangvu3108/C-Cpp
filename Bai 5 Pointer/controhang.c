#include <stdio.h>

int main() {
    int a = 6;
    int b = 8;
    const int* ptr = &a;

    printf("%d\n", *ptr);  // 6

    // Gán địa chỉ mới
    ptr = &b;
    printf("%d\n", *ptr);  // 8

    // Error: assignment of read-only location '*ptr'
    // *ptr = 3;

    return 0;
}