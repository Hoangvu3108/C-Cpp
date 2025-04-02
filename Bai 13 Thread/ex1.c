#include<stdio.h>
 
void  delay1s ()
{
    for (int i=0;i<100000000;i++);

}
void task1(){
    static int count =0;
    count ++;
    printf(" COUNT TASK1 :%d\t",count);
    delay1s();
}
void task2(){
    static int count=0;
    count ++;
    printf("Count task2: %d \n",count);
    delay1s();
}
int main (int argc, char const*argv[])
{
    while(1)
    {
        task1();
        task2();
    }
}