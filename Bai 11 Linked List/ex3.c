#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    int data; 
    struct Node* next;
} Node;

Node *createNote(int data)
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
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNote(data);
    if (newNode == NULL) {
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main()
{
    Node* head = NULL;
    insertAtPosition(&head, 1, 0); // Insert 1 at position 0
    insertAtPosition(&head, 2, 1); // Insert 2 at position 1
    insertAtPosition(&head, 3, 2); // Insert 3 at position 1 (between 1 and 2)
    insertAtPosition(&head, 4, 2); // Insert 4 at position 3 (end of the list)

    printList(head); // Output: 1 3 2 4

    // Free the allocated memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;

}