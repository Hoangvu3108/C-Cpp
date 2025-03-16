# 1. The compilation process of Compiler 
## 1.1. Quá trình biên dịch một chương trình C/C++
- Quá trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ máy,đảm bảo máy tính có thể thể hiểu và thực thi ngôn ngữ của máy tính.
- Quá trình đó được chia thành 4 giai đoạn:
- Giai đoạn tiền xử lý (Pre- processor):
- Giai đoạn Dịch ngôn ngữ bậc cao sang ngôn ngữ máy (Compiler)
- Giai đoạn dịch asembly sang ngôn ngữ máy (Asembler) 
- Giai đoạn liên kết (Linker)

![Example](h1.png)
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
### 1.1.4. Giai đoạn liên kết (Linker)
- Giai đoạn này sẽ liên kết các file Object tạo tahnhf một chương trình duy nhất 
- Tạo thành một file.exe
### 1.1.5. Giai đoạn thực thi (Loader)
- File chạy cuối cùng sẽ được nạp lên RAM và thực thi bởi CPU
#### 1.1.5.1. Cú pháp sử dụng để mixflile và build nhiều file:
'''
- gcc -c main.c -o main.o
- gcc -c test.c -o main.o 
- gcc main.o test.o -o main.o
- ./main
'''
