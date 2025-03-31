#include <stdio.h>

int main() {
    int num = 10;         // Bien so nguyen
    int *ptr1 = &num;     // Con tro tro den num
    int **ptr2 = &ptr1;   // Con tro tro den ptr1 (pointer to pointer)

    // Hien thi gia tri va dia chi cua num
    printf("Gia tri cua num: %d\n", num);
    printf("Dia chi cua num: %p\n\n", (void*)&num);

    // Hien thi gia tri va dia chi cua ptr1
    printf("Gia tri cua ptr1 (dia chi cua num): %p\n", (void*)ptr1);
    printf("Gia tri tro toi boi *ptr1: %d\n", *ptr1);
    printf("Dia chi cua ptr1: %p\n\n", (void*)&ptr1);

    // Hien thi gia tri va dia chi cua ptr2
    printf("Gia tri cua ptr2 (dia chi cua ptr1): %p\n", (void*)ptr2);
    printf("Gia tri tro toi boi **ptr2: %d\n", **ptr2);
    printf("Dia chi cua ptr2: %p\n", (void*)&ptr2);

    return 0;
}
