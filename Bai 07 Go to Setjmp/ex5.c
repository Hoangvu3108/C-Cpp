#include "stdio.h"
#include "setjmp.h"

jmp_buf buf;

double divide(int a,int b)
{
    if( a == 0 && b == 0){
        longjmp(buf,1);   
    }
    else if(a != 0  && b == 0){
        longjmp(buf,2);
    }
    return (double)(a/b);
}

int main(){
    int exception;

    if((exception = setjmp(buf)) == 0 )
    {
        double kq = divide(8,0);
        printf("exception = %f\n",kq);
    }
    else if(exception == 1)
    {
        printf("exception khong ton tai\n");
    }
    else if(exception == 2)
    {
        printf("Chia cho 0\n");
    }

    return 0;
}