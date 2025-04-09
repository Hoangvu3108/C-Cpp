 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct Node {
    int data; // Dữ liệu của nút
    struct Node* next; // Con trỏ trỏ đến nút tiếp theo
} Node;
// Hàm tạo một nút mới với dữ liệu được cung cấp
Node *createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút mới
    if (newNode == NULL) { // Kiểm tra nếu cấp phát bộ nhớ thất bại
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data; // Gán dữ liệu cho nút
    newNode->next = NULL; // Gán con trỏ next của nút là NULL
    return newNode; // Trả về con trỏ đến nút mới
}

// Hàm thêm một nút vào cuối danh sách liên kết
void push_back(Node **array, int data) {
    Node* newNode = createNode(data); // Tạo một nút mới với dữ liệu được cung cấp
    
    if(*array == NULL) { // Nếu danh sách liên kết rỗng
        *array = newNode; // Gán nút mới làm nút đầu tiên
        return;
    }
    Node *current = *array; // Bắt đầu từ nút đầu tiên
    while (current->next != NULL) { // Duyệt đến nút cuối cùng
        current = current->next;
    }
    current->next = newNode; // Gán nút mới vào cuối danh sách
}

int main () {
    Node* head = NULL; // Khởi tạo danh sách liên kết rỗng

    // Thêm các nút vào danh sách liên kết
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    // In dữ liệu của các nút trong danh sách liên kết
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Giải phóng bộ nhớ đã cấp phát
    current = head;
    while (current != NULL) {
        Node* temp = current; // Lưu trữ nút hiện tại
        current = current->next; // Chuyển sang nút tiếp theo
        free(temp); // Giải phóng bộ nhớ của nút hiện tại
    }

    return 0; // Kết thúc chương trình
}