#  STDARG - ASSERT
1. Thư viện STDARG
Bình thường nếu tính tổng số 2 thì có một hàm, tổng 3 số thì có một hàm nữa, tuy nhiên cần tính tổng nhiều số thì làm như thế nào thì cần có thư viện stdarg. 

Thư viện stdarg.h hỗ trợ với số lượng tham số không xác định: Một số từ khóa:

- **va_list**: ```va_list``` là kiểu dữ liệu của tập hợp các đối số không xác định. Bản chất là con trỏ kiểu ```char``` được định nghĩa lại tên bằng ``` typedef : type char* va_list ```.


- **va_start(va,count)**: Hàm này mang các kí tự vào chuỗi ```va```. Cách hoạt động của nó là sẽ tạo một con trỏ có giá trị bằng địa chỉ kí tự đầu tiên của chuỗi không xác định và thực hiện vòng lặp so sánh các kí tự trong chuỗi có giống với từng kí tự của label count không và con trỏ địa chỉ tăng dần dần ứng với địa chỉ của các kí tự tiếp theo của chuỗi. Sau khi xác định được kí tự giống với label count thì mới bắt mang các kí tự sau dấu **,** vào chuỗi **va**

-  **va_arg(va,type)**: Lấy giá trị của tham số tiếp theo từ chuỗi và ép kiểu nó sang kiểu dữ liệu được chỉ định. Khi gọi hàm **va_arg(va,type)** thì nó đọc giá trị tại ô phía sau **va_start** và trỏ tới ô tiếp theo. 

-  **va_end(va_list ap)** : Kết thức quá trình xử lý các tham số, giải phóng tài nguyên liên quan.

**Ví dụ nhập vào 5 tham số**
```c
#include <stdio.h>
#include <stdarg.h>

void display(int count, ... ){
    va_list va;
    va_start(va, count);

    for (int i=0;i<count;i++)
    {
        printf("Value at %d: %d\n",i,va_arg(va,int));
    }
    va_end(va);
}
int main ()
{
    display(5,6,8,11,20,03);
    return 0;
}
```
**Ví dụ**
```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    int total = 0;

    // Bắt đầu đọc các tham số
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Lấy từng tham số kiểu int
    }
    // Kết thúc xử lý tham số
    va_end(args);

    return total;
}

int main() {
    printf("Sum of 1, 2, 3 is: %d\n", sum(5, 1, 2, 3,4,5));
    printf("Sum of 10, 20 is: %d\n", sum(2, 10, 20));
    return 0;
}

```
**Thư viện ASSERT**
Thư viện assert.h là thư viện để hỗ trợ debug chương trình
- **Hàm assert()**: dùng để kiểm tra điều kiện tại thời gian chạy(runtime), nếu đúng thì chương trình tiếp tục còn sai thì dừng lại và in ra thông báo lỗi.
**Ví dụ**
```c
#include <stdio.h>
#include <assert.h>

double thuong(int a, int b) {
    assert( b != 0 && "Mau bang 0");
    return (double) a/b;
}

int main() {
    printf("Thuong: %f\n", thuong(6, 0)); 
    return 0;
}
```
**Báo lỗi**
```c
File: ex3.c, Line 5

Expression: b != 0 && "Mau bang 0"
```
Thường thấy hơn sẽ sử dụng macro để định nghĩa một lỗi.
**Ví dụ**
```c
#include <stdio.h>
#include <assert.h>

// Macro LOG để kiểm tra điều kiện và hiển thị thông báo lỗi
#define LOG(condition, msg) assert((condition) && (msg))

double thuong(int a, int b) {
    // Kiểm tra điều kiện b != 0
    LOG(b != 0, "Denominator cannot be 0");
    return (double)a / b; // Trả về kết quả phép chia nếu điều kiện đúng
}

int main() {
    printf("Result: %.2f\n", thuong(6, 2)); // Kết quả hợp lệ
    printf("Result: %.2f\n", thuong(6, 0)); // Gây lỗi vì b = 0
    return 0;
}

```