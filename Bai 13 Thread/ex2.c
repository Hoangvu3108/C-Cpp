// #include<stdio.h>
// #include<pthread.h>
// #include <unistd.h>
// void *task1(void *data)
// {
//     static int i=0;
//     while (1)
//     {
//         printf("count task1: %d\n",i++);
//         sleep(1);
//     }
// }
// void *task2(void *data)
// {
//     static int i=0;
//     while (1)
//     {
//         printf("count task2: %d\n",i++);
//         sleep(3);
//     }
// }
// void *display(char *a)
// {
//     while (1){
//         printf("%s\n",a);
//         sleep(1);
//     }
// }
// int main (int argc, char const *argv[])
// {   
//     pthread_t t1,t2,t3;
//     pthread_create(&t1, NULL,task1, NULL);
//     pthread_create(&t2, NULL,task2, NULL);
//     while(1){}
// }
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *task1(void *data) {
    static int i = 0;
    while (1) {
        printf("count task1: %d\n", i++);
        sleep(1);
    }
    return NULL;
}

void *task2(void *data) {
    static int i = 0;
    while (1) {
        printf("count task2: %d\n", i++);
        sleep(3);
    }
    return NULL;
}

void *display(void *arg) {
    char *a = (char *)arg;  // Ép kiểu void* về char*
    while (1) {
        printf("%s\n", a);
        sleep(1);
    }
    return NULL;
}

int main() {   
    pthread_t t1, t2, t3;
    
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    
    char msg[] = "Hello from display task";
    pthread_create(&t3, NULL, display, (void *)msg);

    // Đợi các luồng hoàn thành (thực tế không bao giờ kết thúc vì các luồng chạy vô hạn)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

