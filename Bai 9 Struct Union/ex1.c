#include <stdio.h>
#include<stdint.h>
struct Example {
    uint8_t a;     // 1 byte
    uint16_t b;      // 4 bytes
    uint32_t c;     // 1 byte
};

int main() {
    printf("Size of struct Example: %zu bytes\n", sizeof(struct Example));
    return 0;
}