#include<stdio.h>

#define VALUE 100
int main()
{   
    #if VALUE == 10 // Điệu kiện này không đúng nên nó sẽ không in ra giá trị của VALUE
        printf("Value of Value is: %d\n", VALUE);
    
    #elif VALUE == 20 // Điều kiện này không đúng nên nó sẽ không in ra giá trị của VALUE
        printf("Value of Value is: %d\n", VALUE);
    
    #else  // Điều kiện này đúng nên nó sẽ in ra giá trị của VALUE  
        printf("Value of Value is: %d\n", VALUE);
    #endif
}