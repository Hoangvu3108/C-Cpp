#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // Cấp phát bộ nhớ cho 6 phần tử kiểu uint16_t bằng hàm calloc
    uint16_t *ptr = NULL;
    ptr = (uint16_t*)calloc(6, sizeof(uint16_t));

    // In địa chỉ và giá trị của từng phần tử trong mảng
    for (int i = 0; i < 6; i++) {
        // printf("Dia Chi: %p, gia tri: %d\n", (void*)(ptr + i), ptr[i]);
         printf("dia chi: %p, gia tri: %d\n", (uint16_t*)ptr+i, *((uint16_t*)ptr+i));
    }
    // Giải phóng bộ nhớ đã cấp phát
    free(ptr);

    return 0;
}

//  #include<stdio.h>
// #include<stdlib.h>
// #include<stdint.h> 
// int main (){
//     uint16_t *ptr= NULL;
//     ptr = (uint16_t*)calloc(6, sizeof(uint16_t));
//     for (int i=0; i<6; i++){
//         printf("dia chi: %p, gia tri: %d\n", (uint16_t*)ptr+i, *((uint16_t*)ptr+i));
//     }
//     free(ptr);
// }