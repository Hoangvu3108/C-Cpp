// Bài 2: Viết chương trình quản lý stack với các thao tác push, pop và kiểm tra stack rỗng.
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty(Stack stack) {
    return stack.top == -1;
}

int pop(Stack *stack) {
    if (!is_empty(*stack)) {
        printf("Popped %d from stack\n", stack->items[stack->top]);
        return stack->items[stack->top--];
    } else {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 3);

    // Push các phần tử vào stack
    stack1.items[++stack1.top] = 10;
    stack1.items[++stack1.top] = 20;
    stack1.items[++stack1.top] = 30;
    stack1.items[++stack1.top] = 40;
    stack1.items[++stack1.top] = 50;
    stack1.items[++stack1.top] = 60;
    // Hiển thị số lượng phần tử và các giá trị trong stack
    printf("Stack has %d elements: ", stack1.top + 1);
    for (int i = 0; i <= stack1.top; i++) {
        printf("%d ", stack1.items[i]);
    }
    printf("\n");
    // Pop các phần tử từ stack đến khi stack rỗng
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);  // Thử nghiệm khi stack rỗng

    return 0;
}