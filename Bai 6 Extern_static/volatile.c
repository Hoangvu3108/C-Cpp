#include <stdio.h>
#include <stdbool.h>
volatile bool button_pressed = false;  // Có volatile

void button_isr() {
    button_pressed = true;
}

int main() {
    while (!button_pressed) {  
        // Luôn kiểm tra giá trị mới của button_pressed
    }
    
    printf("Button was pressed!\n");
    return 0;
}