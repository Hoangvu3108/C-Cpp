#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
typedef struct Stack
{
    int32_t *data;
    int32_t top;
    int32_t size;
} Stack;

void initialize (Stack *stack, int32_t size)
{
   stack-> data= (uint32_t *)malloc(size * sizeof(uint32_t));
    stack->top = -1;
    stack->size = size;
}

int isFull(Stack stack)
{
    return stack.top == stack.size-1;
}
int isEmpty(Stack stack)
{
    return stack.top == -1;
}
void push(Stack *stack,int32_t value)
{
    if(!isFull(*stack))
    {
        stack->data[++stack->top]  =value;
        printf("Pushed %d to stack\n", value);
    }
    else 
    {
        printf("Stack overflow\n");
    }
}
int main ()
{
     Stack stack1;
        initialize(&stack1, 5);

        push(&stack1, 10);
        push(&stack1, 20);   
        push(&stack1, 30);
        push(&stack1, 40);       
        push(&stack1, 50);
        // push(&stack, 60); // This will cause stack overflow
        
}