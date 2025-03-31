#include <stdio.h>

int main()
{
    int *ptr=NULL;
    printf("Pointer is %p\n", ptr);
    if (ptr != NULL)
    {
        printf("Pointer is NOT NULL\n"); 
    }
    else
    {
        printf("Pointer is NULL\n");
    }
}