#include <stdio.h>

typedef struct 			// Đây là kiểu dữ liệu,
{				        // Không nằm bất kì trong phân vùng nào!	
    int x;
    int y;
} Point_Data;

int a = 0;			// Biến toàn cục khởi tạo bằng 0
int b;				// Biến toàn cục ko khởi tạo

static int global = 0;		// Biến static toàn cục khởi tạo bằng 0
static int global_2;		// Biến static toàn cục ko khởi tạo

static Point_Data p1 = {5,7};	// Biến p1 này đã khởi tạo có giá trị nên nằm ở DS

void test(){
    static int local = 0;	// Biến static cục bộ khởi tạo bằng 0
    static int local_2;		// Biến static cục bộ ko khởi tạo
}

int main() {
    global = 0;			// Dù thay đổi giá trị nó vẫn nằm ở BSS

    printf("a: %d\n", a);
    printf("global: %d\n", global);

    return 0;
}