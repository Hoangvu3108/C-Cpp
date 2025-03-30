#include<stdio.h>

void exampleFunction()
{
    // static int count = 0; // nếu mà  int count thì sẽ in ra màn hình 3 cái count=1 
    int count=0;
    count++;
    printf("count = %d\n",count);
}
int main()
{
    exampleFunction();
    exampleFunction();
    exampleFunction();
    return 0;
}