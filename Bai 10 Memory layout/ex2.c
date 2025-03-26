#include <stdio.h>

int a = 10;			        // Biến toàn cục khởi tạo khác 0
double d = 20.5;		    // Biến toàn cục khởi tạo khác 0

static int var = 5;		    // Biến static toàn cục khởi tạo khác 0

void test()
{
    static int local = 10;	// Biến static cục bộ khởi tạo khác 0
}

int main()
{  
    a = 15;			// Có thể đọc và thay đổi giá trị của biến
    d = 25.7;
    var = 12;

    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);
    
    return 0;
}