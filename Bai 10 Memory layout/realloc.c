#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;      // Con trỏ mảng động
    int initialSize = 5; // Kích thước ban đầu của mảng
    int newSize = 10;    // Kích thước mới của mảng
    int i;

    // Cấp phát mảng động ban đầu bằng malloc
    arr = (int*)malloc(initialSize * sizeof(int));
    if (arr == NULL) {
        printf("Không đủ bộ nhớ để cấp phát!\n");
        return 1;
    }

    // Khởi tạo giá trị cho mảng ban đầu
    for (i = 0; i < initialSize; i++) {
        arr[i] = i + 1; // Gán giá trị 1, 2, 3, 4, 5
    }

    // In các phần tử ban đầu
    printf("Mang ban dau:\n");
    for (i = 0; i < initialSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Thay đổi kích thước mảng bằng realloc
    arr = (int*)realloc(arr, newSize * sizeof(int));
    if (arr == NULL) {
        printf("Không thể thay đổi kích thước mảng!\n");
        return 1;
    }

    // Khởi tạo các phần tử mới của mảng
    for (i = initialSize; i < newSize; i++) {
        arr[i] = (i + 1) * 10; // Gán giá trị 60, 70, 80, 90, 100
    }

    // In các phần tử sau khi thay đổi kích thước
    printf("Mang sau khi thay doi kich thuoc:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
