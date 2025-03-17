// #include<stdio.h>

// #define Display(a,b)                \
//     printf("Value of a is: %d\n", a); \
//     printf("Value of b is: %d\n", b);  \
//     printf("Value of a+b is: %d\n", a+b);

// int main() {
//     Display(10, 20);

//     return 0;

// }

#include<stdio.h> 
#define SUM(a,b) a+b
int main()
{
    printf("Sum of a and b is: %d\n", SUM(10,20));
    return 0;
}
