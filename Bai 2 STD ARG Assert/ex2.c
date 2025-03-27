#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    int total = 0;

    // Bắt đầu đọc các tham số
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Lấy từng tham số kiểu int
    }
    // Kết thúc xử lý tham số
    va_end(args);

    return total;
}

int main() {
    printf("Sum of 1, 2, 3 is: %d\n", sum(5, 1, 2, 3,4,5));
    printf("Sum of 10, 20 is: %d\n", sum(2, 10, 20));
    return 0;
}
