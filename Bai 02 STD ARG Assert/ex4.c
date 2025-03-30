#include <stdio.h>
#include <assert.h>

// Macro LOG để kiểm tra điều kiện và hiển thị thông báo lỗi
#define LOG(condition, msg) assert((condition) && (msg))

double thuong(int a, int b) {
    // Kiểm tra điều kiện b != 0
    LOG(b != 0, "Denominator cannot be 0");
    return (double)a / b; // Trả về kết quả phép chia nếu điều kiện đúng
}

int main() {
    printf("Result: %.2f\n", thuong(6, 2)); // Kết quả hợp lệ
    printf("Result: %.2f\n", thuong(6, 0)); // Gây lỗi vì b = 0
    return 0;
}
