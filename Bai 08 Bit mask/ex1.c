#include <stdio.h>
#include <stdint.h>

// Hàm in số dưới dạng nhị phân
void print_binary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {  // In từ bit cao đến bit thấp
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    uint8_t a = 0b10101010;  // Ví dụ số nhị phân 8 bit
    uint8_t result = ~a;     // Thực hiện phép NOT trên 8 bit

    printf("Original: ");
    print_binary(a);  // In số gốc dưới dạng nhị phân

    printf("NOT: ");
    print_binary(result);  // In số sau khi NOT

    return 0;
}
