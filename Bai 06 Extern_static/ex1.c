#include <stdio.h>
#include <stdbool.h>

volatile bool flag = false;  // Sử dụng volatile

void ISR() {  
    flag = true;  // Giả sử đây là hàm ngắt
}

int main() {
    while (!flag) {  
        // Luôn đọc lại giá trị flag từ bộ nhớ, không tối ưu hóa
    }
    printf("Ngắt xảy ra, thoát vòng lặp!\n");
    return 0;
}