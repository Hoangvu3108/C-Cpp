/*
* File: ex5.c
* Author: Hoang Long Vu
* Date: 09/04/2025
* Description: This is a sample file to delete a node at the first of a linked list.
*              It includes the definition of the node structure, the function to insert a node,
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int data; 
    struct Node* next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
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

void pop_front(Node **array )
{
    if (*array == NULL) // Nếu danh sách rỗng
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *temp = *array; // Lưu trữ nút đầu tiên
    *array = (*array)->next; // Gán nút tiếp theo làm nút đầu tiên
    free(temp); // Giải phóng bộ nhớ của nút đầu tiên
}
int size(Node* array) {
    int count = 0;
    Node* temp = array;

    // Duyệt qua danh sách và đếm số lượng node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
    }
int main ()
{
    Node *head= NULL;
    push_back(&head, 11);
    push_back(&head, 3);
    push_back(&head, 8);
    push_back(&head, 31);
    push_back(&head, 23);

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    pop_front(&head); // Xóa nút đầu tiên

    pop_front(&head); // Xóa nút đầu tiên
    current =head;
    while (current != NULL)
    {
        printf("%d ", current->data); // In dữ liệu của từng nút
        current = current->next;
    }
    printf("\n");
    printf("Size of the linked list: %d\n", size(head)); // In kích thước của danh sách liên kết
    current = head;
    while (current != NULL) {
        Node* temp = current; // Lưu trữ nút hiện tại
        current = current->next; // Chuyển sang nút tiếp theo
        free(temp); // Giải phóng bộ nhớ của nút hiện tại
    }
    return 0; // Kết thúc chương trình
}