#include<stdio.h>

int main()
{
    int value=15;
     int test=15;
     int *const const_ptr=&value;

     printf("Value: %d\n",*const_ptr);
     *const_ptr=20;
     printf("Value: %d\n",*const_ptr);
}