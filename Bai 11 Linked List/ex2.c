/*
* File: ex2.c
* Author: Hoang Long Vu
* Date: 09/04/2025
* Description: This is a sample file to insert a node at the first of a linked list.
*              It includes the definition of the node structure, the function to insert a node,
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data; // gia tri cua not
    struct Node* next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
void push_front(Node **array, int data)
{
    Node *newNode = createNode(data);

    if(*array == NULL)
    {
        *array = newNode;
        return;
    }
    newNode ->next = *array; // Gán con trỏ next của nút mới là nút đầu tiên
    *array = newNode; // Gán nút mới làm nút đầu tiên
}
int main ()
{   
    Node *head= NULL;
    push_front(&head, 1);
    push_front(&head, 2);   
    push_front(&head, 3);
    push_front(&head, 4);   

    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    current = head; 
    while (current != NULL) {
        Node *temp = current; // Lưu trữ nút hiện tại
        current = current->next; // Chuyển sang nút tiếp theo
        free(temp); // Giải phóng bộ nhớ của nút hiện tại
    }
    return 0;
}