#include<stdio.h>

void ggreetEnglish(){
    printf("Hello\n");
}
void greetFrench(){
    printf("Bonjour\n");
}

int main()
{
    void(*printGreet)(void);
    printGreet = ggreetEnglish;
    printGreet();
    printGreet = greetFrench;
    printGreet();
}