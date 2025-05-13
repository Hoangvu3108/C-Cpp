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

# LESSON 2: STDARG-ASSERT
<details><summary>Chi tiết</summary>
<p>
  
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

</p>
</details>

# LESSON 4: STACK-QUEUE
<details><summary>Chi tiết</summary>
<p>
  
## 1. Stack
### Khái niệm:
Stack(ngăn xếp) là một cấu trúc dữ liệu hoạt động theo nguyên tắc LIFO(Last in first out) tức là phần tử được thêm vào cuối cùng sẽ được lấy ra đầu tiên.
![alt text](image.png)
**Các thao tác trên Stack**
**1.1: Stack.**
- Push trong stack dùng để thêm một phần tử mới vào đỉnh của stack.
- Stack đầy khi chỉ sổ của phần tử đỉnh top bằng kích thước của stack trừ đi 1 (top== size-1)
- Nếu stack đã đầy mà cố tính thêm phần tử nữa bằng cách push, thì quá trình này sẽ không thành công và sẽ gặp phải tình trạng "Stack overflow".
**Ví dụ**
```c
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
typedef struct Stack
{
    int32_t *data;
    int32_t top;
    int32_t size;
} Stack;

void initialize (Stack *stack, int32_t size)
{
   stack-> data= (uint32_t *)malloc(size * sizeof(uint32_t));
    stack->top = -1;
    stack->size = size;
}

int isFull(Stack stack)
{
    return stack.top == stack.size-1;
}
int isEmpty(Stack stack)
{
    return stack.top == -1;
}
void push(Stack *stack,int32_t value)
{
    if(!isFull(*stack))
    {
        stack->data[++stack->top]  =value;
        printf("Pushed %d to stack\n", value);
    }
    else 
    {
        printf("Stack overflow\n");
    }
}
int main ()
{
     Stack stack1;
        initialize(&stack1, 5);

        push(&stack1, 10);
        push(&stack1, 20);   
        push(&stack1, 30);
        push(&stack1, 40);       
        push(&stack1, 50);
        // push(&stack, 60); // This will cause stack overflow
        
}
```
**Kết quả**
```c
Pushed 10 to stack
Pushed 20 to stack
Pushed 30 to stack
Pushed 40 to stack
Pushed 50 to stack
```
**1.2: Pop**
Pop trong stack dùng để xóa một phần tử ở đỉnh của stack.

Khi stack không có phần tử nào thì không thể dùng pop.

Nếu cố tình pop khi stack rỗng, sẽ gặp phải tình trạng gọi là "stack underflow"

**Ví dụ**
```c
// Bài 2: Viết chương trình quản lý stack với các thao tác push, pop và kiểm tra stack rỗng.
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty(Stack stack) {
    return stack.top == -1;
}

int pop(Stack *stack) {
    if (!is_empty(*stack)) {
        printf("Popped %d from stack\n", stack->items[stack->top]);
        return stack->items[stack->top--];
    } else {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 3);

    // Push các phần tử vào stack
    stack1.items[++stack1.top] = 10;
    stack1.items[++stack1.top] = 20;
    stack1.items[++stack1.top] = 30;
    stack1.items[++stack1.top] = 40;
    stack1.items[++stack1.top] = 50;
    stack1.items[++stack1.top] = 60;
    // Hiển thị số lượng phần tử và các giá trị trong stack
    printf("Stack has %d elements: ", stack1.top + 1);
    for (int i = 0; i <= stack1.top; i++) {
        printf("%d ", stack1.items[i]);
    }
    printf("\n");
    // Pop các phần tử từ stack đến khi stack rỗng
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);  // Thử nghiệm khi stack rỗng

    return 0;
}
```
**1.3: Top**
Top trong ```stack``` dùng để lấy giá trị của phần tử ở đỉnh. 

Khi stack không có phần tử nào (tức là stack rỗng), giá trị của top thường sẽ là -1.

Khi thực hiện push hoặc pop , thì giá trị của top cũng sẽ thay đổi cộng hoặc trừ xuống 1.

Khi stack đầy, giá trị top là ```size -1```.
**Ví dụ**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty(Stack stack) {
    return stack.top == -1;
}

int top(Stack stack) {
    if (!is_empty(stack)) {
        printf("Top element: %d\n", stack.items[stack.top]);
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);
    printf("Dia chi stack: %p\n", (void*)&stack1);  // In địa chỉ của stack
    // Push các phần tử vào stack
    stack1.items[++stack1.top] = 10;
    stack1.items[++stack1.top] = 20;
    stack1.items[++stack1.top] = 30;

    // Lấy giá trị phần tử ở đỉnh stack mà không xóa nó
    top(stack1);

    // Thử nghiệm khi stack rỗng
    stack1.top = -1;  // Xóa các phần tử trong stack bằng cách đặt top về -1
    top(stack1);      // Gọi top khi stack rỗng

    return 0;
}

```
**Ví dụ**
```c
#include<stdio.h>
#include<stdint.h>

int giaithua(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else 
    {
        return n * giaithua(n-1);
    }
}
int main ()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);

    if (n<0)
    {
        printf("Error");
    }
    else
    {
        printf("Giai thua cua %d la: %d",n,giaithua(n));
    }
}
```
**Kết quả**
```c
Nhap n:5
Giai thua cua 5 la: 120
```
## 2. Queue
### Khái niệm:
Queue là một cấu trúc dữ liệu tuân theo nguyên tắc FIFO " First in , First our" nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 
![alt text](image-1.png)
### Các thao tác trên stack
#### Enqueue
Enqueue trong hàng chờ queue được sử dụng để thêm một phần tử vào cuối hàng chờ.

Chỉ có thể thực hiện enqueue khi hàng đợi không đầy.

Khi hàng đợi đã đầy, việc gọi enqueue sẽ không thêm phần tử mới và chương trình sẽ báo lỗi "Queue overflow".
**Ví dụ**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    } else {
        printf("Queue overflow\n");
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    enqueue(&queue, 40);  // Hàng đợi đầy, sẽ in ra "Queue overflow"

    return 0;
}
```
#### Dequeue
Dequeue trong hàng chờ queue dùng để lấy phần tử từ đầu hàng chờ ra.

Chỉ có thể sử dụng dequeue khi hàng đợi không rỗng.

Khi hàng đợi rỗng, việc gọi dequeue sẽ không có phần tử nào để lấy ra và chương trình sẽ báo lỗi "Queue underflow".
**Ví dụ**
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        printf("Dequeued %d\n", dequeued_value);
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    // Giả lập việc thêm phần tử vào hàng đợi trước
    queue.items[++queue.rear] = 10;
    queue.items[++queue.rear] = 20;
    queue.items[++queue.rear] = 30;
    queue.front = 0;

    // Dequeue các phần tử
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Thử nghiệm dequeue khi hàng đợi rỗng
    dequeue(&queue);

    return 0;
}
```
#### Front

Front để lấy giá trị phần tử ở đầu hàng đợi mà không xóa nó.
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        printf("Front element: %d\n", queue.items[queue.front]);
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    // Giả lập việc thêm phần tử vào hàng đợi
    queue.items[++queue.rear] = 10;
    queue.items[++queue.rear] = 20;
    queue.items[++queue.rear] = 30;
    queue.front = 0;

    // Lấy phần tử ở đầu hàng đợi mà không xóa nó
    front(queue);

    // Giả lập hàng đợi rỗng và kiểm tra lại
    queue.front = queue.rear = -1;
    front(queue);  // Hàng đợi rỗng, sẽ in "Queue is empty"

    return 0;
}
```
**Ví dụ**
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue an element
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    return 0;
}
```
## 3. Các loại Queue
**Linear queue**(Hàng đợi tuyến tính)
- Trong hàng đợi linear, khi ta dequeue trong trường hợp full queue (size = rear - 1) , thì lúc này ta sẽ không thể enqueue phần tử mới được dù cho có vùng nhớ trống ở đầu vừa được dequeue Cơ ché này được giải thích như sau.
- Khi chưa có giá tri, lúc này hàng đợi rỗng và giá trị của front và rear mặc định là 
![alt text](381855744-62f24d68-44eb-4064-b9cf-501c8867f1af.png)
- Tiếp theo ta sẽ tiến hành enqueue, lúc này chỉ số front và rear sẽ tăng lên 0 trước khi giá trị được enqueue vào
- Tuy nhiên khi ta tiếp tục enqueue, thì front sẽ luôn chỉ tới giá trị ở đầu hàng đợi, trong khi rear sẽ tăng để trỏ tới các vùng nhớ tiếp theo về phía cuối hàng đợi.
- Sau khi hàng đợi đầy, ta tiến hành dequeue thì lúc này do chỉ số rear đã trỏ đến cuối hàng đợi nên nó sẽ không cho phép ta enqueue nữa, mặc dù vùng nhớ ở đầu hàng đợi mà ta vừa dequeue giá trị, đang trống. Chính vì vậy nó sẽ gây lãng phí memory và có thể được coi là 1 nhược điểm của linear queue
=> Khi ta dequeue hết tất cả phần tử trong queue, lúc này chỉ số front bằng với rear, khi đó chúng sẽ được reset về -1. Quá trình enqueue mới được cho phép.
**Circular queue**(Hàng đợi vòng tròn)
- Ta biết rằng 1 linear queue sẽ chỉ được enqueue sau khi queue đã đày bằng cách dequeue toàn bộ phần tử bên trong nó. vậy nên ta sẽ không thể enqueue phần tử mới khi bắt đầu dequeue. Chính vì vậy ta sẽ sử dụng co chế circular queue để giải quyết được vấn đề này
![alt text](382187302-1aace635-b65c-482f-88e9-5560ee928196.png)
- Hình trên mô tả 1 queue được dequeue 3 phần tử và chỉ số front lúc này bằng 3 đang trỏ tới phần tử thứ 4. Trong khi đó chỉ số rear = size - 1. Lúc này cơ chế circular sẽ cho phép rear trỏ đến đầu hàng đợi để enqueue tiếp.
- Hình trên mô tả 1 queue được dequeue 3 phần tử và chỉ số front lúc này bằng 3 đang trỏ tới phần tử thứ 4. Trong khi đó chỉ số rear = size - 1. Lúc này cơ chế circular sẽ cho phép rear trỏ đến đầu hàng đợi để enqueue tiếp
![alt text](382189608-c9fc6a35-624b-4b51-b4e1-d2dfd1fccb16.png)
- Lúc này ta sẽ có thể tiếp tục enqueue cho đến khi các ô trống được lắp đầy
![alt text](382190561-2b1ec340-0185-4801-bac5-3f8d008e58d8.png) 

**So Sành Stack và Queue**
![alt text](399634583-d64c2f7c-3557-4701-850c-7302fbf944c9.png)

</p>
</details>
