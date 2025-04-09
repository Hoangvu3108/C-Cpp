/*
* File: ex4.c
* Author: Hoang Long Vu
* Date: 09/04/2025
* Description: This is a sample file to delete a node at the last of a linked list.
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

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data); // In dữ liệu của từng nút
        current = current->next;
    }
    printf("\n");
}
void pop_back(Node **array )
{
    if (*array == NULL) // Nếu danh sách rỗng
    {
        printf("Danh sach rong\n");
        return;
    }
    Node *current = *array;

    while (current->next->next != NULL)
    {
        current=current->next; // Duyệt đến nút cuối cùng
    }
    free(current->next); // Giải phóng bộ nhớ của nút cuối cùng
    current->next = NULL; // Gán con trỏ next của nút trước đó là NULL
}
int main ()
{
    Node *head = NULL; // Khởi tạo danh sách liên kết rỗng

    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    // In dữ liệu của các nút trong danh sách liên kết
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    pop_back(&head); // Xóa nút cuối cùng

    current = head; // Đặt lại con trỏ current về đầu danh sách
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

}
