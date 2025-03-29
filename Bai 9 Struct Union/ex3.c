#include<stdio.h>
#include<stdint.h>

typedef union{
    uint8_t arr1;
    uint32_t arr2;
    uint16_t arr3;
} frame;

int main (int argc, char const *argv[])
{
    printf("Size = %lu\n",sizeof(frame));

    frame data;

    // printf("Dia chi : %p\n",&data);

    printf("Dia chi data.var1: %p\n", &(data.arr1));
    printf("Dia chi data.var1: %p\n", &(data.arr2));
    printf("Dia chi data.var1: %p\n", &(data.arr3));
    
    data.arr1=5;
    data.arr2=15;
    data.arr3=20;
    
    printf("arr1 = %d\n",data.arr1);
    printf("arr2 = %d\n",data.arr2);
    printf("arr3 = %d\n",data.arr3);
}