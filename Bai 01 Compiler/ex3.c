#include<stdio.h>

#define Feature 1

int main() 
{   
    // Kiểm tra điều kiện có được định nghĩa hay không nếu định nghĩa thì in ra dòng chữ Feature is defined
    #ifdef Feature
        printf("Feature is defined\n");
    #endif // Kết thúc điều kiện
    // kiểm tra điều kiện có được định nghĩa hay không nếu không được định nghĩa thì in ra dòng chữ Feature is not defined
    #ifndef Feature_2 
    #define Feature_2  // thực ra là không cần thiết vì nó đã được định nghĩa bởi câu lệnh #ifndef Feature_2 rồi 
    printf("Feature_2 is not defined\n");
    #endif
    return 0;
}