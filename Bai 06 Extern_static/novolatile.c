#include <stdio.h>
#include <stdbool.h>

bool button_pressed = false;  // Không có volatile

void button_isr() {
    button_pressed = true;  // Được gọi khi nút nhấn được bấm
}

int main() {
    while (!button_pressed) {  
        // Compiler có thể tối ưu hóa bỏ qua vòng lặp này vì nó "nghĩ" button_pressed không thay đổi
    }
    
    printf("Button was pressed!\n");
    return 0;
}