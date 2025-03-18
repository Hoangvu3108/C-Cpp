# 1. The compilation process of Compiler 
<details><summary>Chi tiết</summary>
<p>
  
## 1.1. Quá trình biên dịch một chương trình C/C++
- Quá trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ máy,đảm bảo máy tính có thể thể hiểu và thực thi ngôn ngữ của máy tính.
- Quá trình đó được chia thành 4 giai đoạn:
- Giai đoạn tiền xử lý (Pre- processor):
- Giai đoạn Dịch ngôn ngữ bậc cao sang ngôn ngữ máy (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asembler) 
- Giai đoạn liên kết (Linker)


<p align="center">
  <img src="Images/h1.png" alt="Compiler Macro" width="600">
</p>

### 1.1.1. Giai đoạn tiền xử lý (Preprocessor)
- Giai đoạn này sẽ nhận mã nguồn và xóa bỏ tất cả mọi chú thích, comment của chương trình , xử lý các chỉ thị tiền xử lý.

**Ví dụ:** #ifndef, #include, #define
- Giai đoạn này sẽ chuyển toàn bộ các file.c và file.h thành file.i

### 1.1.2. Giai đoạn biên dịch (Compiler)
- Giai đoạn sẽ phân tích và chuyển sang ngôn ngữ bậc cao sang ngôn ngữ bậc thấp assembly.
- Giai đoạn này sẽ chuyển file.i thành file.s

### 1.1.3. Giai đoạn dịch ngôn ngữ (Assembler) 
- Giai đoạn này sẽ chuyển file.s thành file.o 
- Giai đoạn này sẽ dịch chương trình sang mã máy 0 và 1 để ra các file Object(.o)
- 
### 1.1.4. Giai đoạn liên kết (Linker)
- Giai đoạn này sẽ liên kết các file Object tạo thành một chương trình duy nhất 
- Tạo thành một file.exe
  
### 1.1.5. Giai đoạn thực thi (Loader)
- File chạy cuối cùng sẽ được nạp lên RAM và thực thi bởi CPU

#### 1.1.5.1. Cú pháp sử dụng để mixflile và build nhiều file:

```c
     gcc -c main.c -o main.o
     gcc -c test.c -o main.o 
     gcc main.o test.o -o main.o
     ./main
```

# 2. Macro

## 2.1. Chỉ thị tiền xử lý 
 Chỉ thị tiền xử lý là những chỉ thị cung cấp cho bộ tiền xử lý để xử lý các thông tin trước khi quá trình biên dịch bắt đầu. Các chỉ thị tiền xử lý bắt đầu quá trình bắt đầu bằng kí tự **#**.

 - **#include**: Chèn nội dung của file được include vào file.i, giúp cho chương trình tái sử dụng mã nguồn và phân chia chương trình thành các phần nhỏ, giúp quản lý mã nguồn hiệu quả. 

```c
#include <stdio.h>
#include <main.h>
```
- **#define**: Được sử dụng để định ghĩa các hằng số, hay tập hợp các đoạn mã thay thế, không có kiểu dữ liệu. Việc sử dụng ```#define``` để định nghĩa cách chỉ thị tiền xử lý được gọi là Macro.
```c
#define pi  3.14
```
- **#undef** : Được sử dụng để hủy định nghĩa của một macro ```#define ``` trước đó.
```c
#include<stdio.h>
#define MAX 100

int main() {
    printf("Value of MAX is: %d\n", MAX);

    // Bỏ định nghĩa của MAX
    #undef MAX

    // định nghĩa lại giá trị của MAX
    #define MAX 200

    printf("Value of MAX after defining là: %d\n", MAX);

    return 0;
}
``` 
- **#if, #elif, #else**: Kiểm tra điều kiện của Macro 
 ```c
 #include<stdio.h>

#define VALUE 100
int main()
{   
    #if VALUE == 10 // Điệu kiện này không đúng nên nó sẽ không in ra giá trị của VALUE
        printf("Value of Value is: %d\n", VALUE);
    
    #elif VALUE == 20 // Điều kiện này không đúng nên nó sẽ không in ra giá trị của VALUE
        printf("Value of Value is: %d\n", VALUE);
    
    #else  // Điều kiện này đúng nên nó sẽ in ra giá trị của VALUE  
        printf("Value of Value is: %d\n", VALUE);
    #endif
}
 ```
 - **#ifdef, #ifndef**: Kiểm tra xem một macro đã được định nghĩa hay chưa.
 **#ifdef** dùng để kiểm tra một Macro đã được định nghĩa hay chưa, nếu macro đã định nghĩa thì mã nguồn sau ```#ifdef``` sẽ được biên dịch. 
 **#ifndef** dùng để kiểm tra một Macro đã được định nghĩa hay chưa, nếu marco chưa được định nghĩa thì mã nguồ nsau ```#ifndef``` sẽ được biên dịch. Macro này thường được dùng ở các thư viện file.h để kiểm tra marcrp câu lệnh ```#ifndef``` nếu chưa có thì sẽ định nghĩa ngay sau đó bằng câu lệnh ```#define``` với tên tương ướng của ```#ifndef```.  

 ```c
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
 ```
 ### Macro function 
 **Macro function** sử dụng với những tham số truyền vào để hoạt động giống như cách gọi hàm thông thường 
 Khi sử dụng **Macro function**có nhiều dòng thì mỗi dòng (trừ dòng cuối) phải kết thức bằng ký từ ```\```.
 **Ví dụ 1**
 ```c
 #include<stdio.h>

#define Display(a,b)                \
    printf("Value of a is: %d\n", a); \
    printf("Value of b is: %d\n", b);  \
    printf("Value of a+b is: %d\n", a+b);

int main() {
    Display(10, 20);

    return 0;
}
 ```
 **Ví dụ 2**
 ```c
 #include<stdio.h> 
#define SUM(a,b) a+b
int main()
{
    printf("Sum of a and b is: %d\n", SUM(10,20));
    return 0;
}

 ```
 Ưu điểm của macro function so với function là tối ưu về tốc độ nhưng không tối ưu về bộ nhớ. Cụ thể:
-Ngược lại với function ví dụ hàm sum chỉ định nghĩa một lần và địa chỉ cấp phát cho hàm sum là cố định định là tối ưu bộ nhớ nhưng chương trình sẽ chạy chậm hơn macro function.
- với Macro function sẽ thay thế trục tiếp mã trong chương trình chính tại vị trí marco gọi nên tốc đọ thực thi nhanh hơn. Nhưng mỗi lần khi macro được sử dụng sẽ tạo ra một bản sao, nên chương trình sẽ chiếm nhiều bộ nhớ RAM hơn. 
## Một số toán tử trong Macro
**Toán tử #**: Tự chuẩn hóa kiểu chuỗi cho tham số nhập vào
**Toán tử ##**: nối các chuỗi lại với nhau 
**Variadic macro**: là một dạng macro cho phép nhạn một số lượng biến tham số có thể thay đổi, giúp định nghĩa các Macro có thể xử lý một lượng biến đầu vào khác nhau 
```c
#include <stdio.h>

// Định nghĩa một variadic macro
#define PRINT_ARGS(format, ...) printf(format, __VA_ARGS__)

int main() {
    // Sử dụng variadic macro để in ra các giá trị
    PRINT_ARGS("This is a variadic macro example: %d, %f\n", 42, 3.14);

    return 0;
}
```

</p>
</details>
