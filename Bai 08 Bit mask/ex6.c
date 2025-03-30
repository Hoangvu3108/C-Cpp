#include<stdio.h>
#include<stdint.h>
// Hàm in số dưới dạng nhị phân

void print_binary(uint8_t n) {
    for (int i = 7; i >= 0; i--) {  // In từ bit cao đến bit thấp
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}
int main()
{
    uint8_t a= 0b10100110;
    uint8_t shift_value= a >>4;

    printf("Original a: ");
    print_binary(a);

    printf("Shift_left_value a : ");
    print_binary(shift_value);
} //10100110
  //00001010 