#include<stdio.h>
#include<setjmp.h>

jmp_buf buffer;

int main()
{
    int i=setjmp(buffer);
    if (i==0)
    {
        printf("First time\n");
    }
    else if (i==3)
    {
        printf("Third time\n");
    }
    else
    {
        printf("Second time\n");
    }
    longjmp(buffer,0);
    return 0;
}

// #include "stdio.h"
// #include "setjmp.h"

// jmp_buf buf;

// int main(){
//     int exception = setjmp(buf);
    
//     if(exception == 0 )
//     {
//         printf("exception = %d\n",exception);
//     }
//     else if(exception == 3)
//     {
//         printf("exception = %d\n",exception);
//     }

//     longjmp(buf,3);
//     return 0;
// }