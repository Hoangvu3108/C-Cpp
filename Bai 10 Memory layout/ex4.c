
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main ( int argc, char const *argv[]){
    uint16_t *ptr= NULL;
    ptr = (uint16_t*)malloc (sizeof(uint16_t)*4);

    for (int i=0; i<4; i++){
        ptr[i]=2*i;
    }
    for (int i=0; i<8; i++){
        printf("dia chi: %p, gia tri: %d\n", (uint8_t*)ptr+i, *((uint8_t*)ptr+i));
        // printf("dia chi: %p, gia tri: %d\n", ptr+i, *ptr+i);
    }
    free (ptr);
}