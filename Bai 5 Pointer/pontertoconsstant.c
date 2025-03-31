#include<stdio.h>
#include<assert.h>
#include <stdint.h>

void swap(char *string)  //string =0x01 // void swap (const char *string)
{
    *string = 'w';
    // printf("Text: %s\n",string);
    *(string+1)= 'H';
}

int main ()
{
    char array []= "Hello World";

    printf("Text: %s\n",array);
    swap(array); 
    printf("Text: %s\n",array);
}
