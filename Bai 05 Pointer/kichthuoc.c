#include <stdio.h>
#include <stdint.h>

int main ()
{
    printf("Size: %lu byte \n", sizeof(int *));
    printf("Size: %lu byte\n", sizeof(double *));  
    printf("Size: %lu byte \n", sizeof(uint8_t *));  
}