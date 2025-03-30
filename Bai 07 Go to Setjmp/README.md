# Goto - setjmp.h
- **Vấn đề**: Trong nhiều vòng lặp while kết hợp với nhiều vòng lặp for thì việc thoát chương trình vòng lặp for và thoát ra ngoài vòng lặp for, ta phải dùng nhiều câu lệnh ```break```, điều này khiến cho chương trình phức tạp nên cần có câu lệnh từ vòng lặp for và thoát khỏi chương trình ngay lập tức đó là ```goto```.
## Goto
```goto``` được định nghĩa là cho phép chương trình nhảy đến một nhãn ```label``` đã được định nghĩa sẵn trước đã đặt trước ở trong hàm đó.
Tù khóa ```goto``` cung cấp khả năng kiểm soát luồng chạy của chương trình.
**Ví dụ**
```c
#include<stdio.h>

int main ()
{
    int i=0;
    start: 
    if (i>=10)
    {
        goto end;
    }
    printf("%d\n",i);
    i++;
    goto start;
    end:
    printf("End of the program");
    return 0;
}
```
**Kết quả**
```c
1
2
3
4
5
6
7
8
9
End of the program
```
✈	Khi thỏa mãn điều kiện i>=10 thì chương trình sẽ không chạy phần if mà bỏ qua để chạy câu lệnh print và tăng i lên.
✈	Khi thỏa mãn chương trình thì  sẽ thực hiện câu lệnh go to end và thực hiện câu lệnh của label end.
- Go to thường được sử dụng trong các vấn đề như thoát khỏi nhiều cấp vòng lặp.
**Ví dụ**
**Sử dụng goto**
```c
#include <stdio.h>

int main()
{
    
        for (int i=0; i<10;i++)
        {   
            for (int j=0; j<10; j++)
            {
                if (i==5 && j==6)
                {
                    printf("i=%d, j=%d\n",i,j);
                    goto end;
                }
            }
        }
        end:
        printf("End of the program");
    
}

```
**Ví dụ**
**Không sử dụng goto**
```c
#include <stdio.h>
int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 5 && j == 6)
            {
                printf("i=%d, j=%d\n", i, j);
                break;
            }
        }
        if (i == 5) 
        {
            break;
        }
    }
    printf("End of the program");
}
```

**Kết quả**
```c
i=5, j=6
End of the program
```
Ta có thế thấy nếu không sử dụng goto thì ta phải dùng hai lệnh break.Tuy nhiên với nhiều vòng lặp thì ta có thể thay code sẽ phức tạp lên rất nhiều nên chúng ta sử dụng lệnh ```goto``` để tối ưu bài toán.
### Ứng dụng:
- Câu lệnh Goto có thể dùng để tắt đèn LED hay còn gọi là quét LED muốn dừng lại tất cả các đèn LED chỉ với việc bấm nút thì khi bấm nghĩa là thực hiện lệnh goto nó sẽ ra khỏi vòng lặp và thực hiện lệnh khác.

## setjmp.h
```setjmp.h``` là thư viện cung cấp hai hàm ```setjmp``` và ```longjmp```. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ C.
- Là một biến ```jmp_buf``` dùng để lưu trữ trạng thái của chương trình tại thời điểm gọi hàm setjmp.
- Hàm longjmp được gọi để nhảy ngược lại tráng thái đã được lưu bởi setjmp.
**Ví dụ**
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
#define THROW(x) longjmp(buf, (x))


double divide(int a, int b) {
    if (b == 0) {
        THROW(1); // Mã lỗi 1 cho lỗi chia cho 0
    }
    return (double)a / b;
}

int main() {
    int a = 10;
    int b = 2;
    double result = 0.0;

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("Error: Divide by 0!\n");
    }


    // Các xử lý khác của chương trình
    return 0;
}
```
**Ví dụ**
```c
#include "stdio.h"
#include "setjmp.h"

jmp_buf buf;

double divide(int a,int b)
{
    if( a == 0 && b == 0){
        longjmp(buf,1);   
    }
    else if(a != 0  && b == 0){
        longjmp(buf,2);
    }
    return (double)(a/b);
}

int main(){
    int exception;

    if((exception = setjmp(buf)) == 0 )
    {
        double kq = divide(8,0);
        printf("exception = %f\n",kq);
    }
    else if(exception == 1)
    {
        printf("exception khong ton tai\n");
    }
    else if(exception == 2)
    {
        printf("Chia cho 0\n");
    }

    return 0;
}
```
**Kết quả**
```c
Chia cho 0
```