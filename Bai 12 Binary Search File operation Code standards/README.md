# Tìm kiếm nhị phân-  File operations - code standard
## 1. Binary search
Tìm kiếm nhị phân là một thuật toán dùng để tìm kiếm vị trí của một phần tử trong một mảng đã được sắp xếp. Thuật toán này giảm đáng kế số lượng phép so sánh cần thực hiện so với việc tìm kiếm tuyển tính. 
**Mô tả :**
- Với một mảng nhập từ bàn phím và sắp xếp một cách không theo trình tự.
- Sắp xếp mảng : mảng cần được sắp xếp theo thứ tự tăng dần hoặc giảm dần
- Khởi tạo biến: Đặt hai biến left và right, lần lượt là vị trí bắt đầu và kết thúc của phần mảng cần xem xét. Ban đầu, left= 0 và right= n-1 (n là kích thước của mảng).
- Xác định điểm giữa của mảng :``` mid= (right + left)/2``` 
- So sánh phần tử tại vị trí với giá trị cần tìm:
      
    -   Nếu ```arr[mid] == x```: Phần tử cần tìm được tìm thấy tại chỉ số mid.

    -    Nếu ```arr[mid] > x```: Giới hạn phạm vi tìm kiếm chỉ còn nửa bên trái mảng, do x chỉ có thể nằm trong khoảng từ left đến mid - 1.

     -   Nếu ```arr[mid] < x```: Giới hạn phạm vi tìm kiếm chỉ còn nửa bên phải mảng, do x chỉ có thể nằm trong khoảng từ mid + 1 đến right.
- Lặp lại quá trình Xác định điểm giữa của mảng :``` mid= (right + left)/2```  và So sánh phần tử tại vị trí với giá trị cần tìm với phạm tìm kiếm mới cho đến khi tìm thấy phần tử hoặc phạm vi tìm kiếm trởi nên rỗng (khi left > right) là không tìm thấy phần tử.
```c
int binarySearch(int *arr, int left, int right, int target)
{
   if (right >= left)
   {
        int mid = left + (right  - left)/2;
 
        // Nếu giá trị giữa mảng bằng với x, trả về chỉ số của nó
        if (arr[mid] == target)  return mid;
 
        // Nếu x nhỏ hơn giá trị giữa mảng, tìm kiếm trong phần trái của mảng
        if (arr[mid] > target) return binarySearch(arr, left, mid-1, target);
 
        // Nếu x lớn hơn giá trị giữa mảng, tìm kiếm trong phần phải của mảng
        return binarySearch(arr, mid+1, right, target);
   }
}
```
## 2. File operations
Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file (.txt,.csv,v.v).
- Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file. 
- CSV (Comma-Separated Values) là một định dạng file văn bản đơn giản dùng để lưu trữ dữ liệu bảng.
### Mở file 
Để mở một file, bạn có thể sử dụng hàm fopen(). Hàm này trả về một con trỏ FILE, và cần được kiểm tra để đảm bảo file đã mở thành công.
```c
FILE *file = fopen(const char *file_name, const char *access_mode);
```
Với :
- Input parameter:
    - file_name: tên file muốn mở.
    - access_mode: chế độ truy cập file.
- r : Mở file với chế độ chỉ đọc file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb : Mở file với chế độ chỉ đọc file theo định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- w : Mở file với chế độ ghi vào file. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- wb : Mở file với chế độ ghi vào file theo định dạng binary. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- a : Mở file với chế độ nối. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- ab : Mở file với chế độ nối dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- r+ : Mở file với chế độ đọc và ghi file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb+ : Mở file với chế độ đọc và ghi file dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
 ### Đọc file
- **fscanf()**	Sử dụng chuỗi được định dạng và danh sách đối số biến để lấy đầu vào từ một File
- **fgets()**	Copy nội dung trong File vào mảng dùng để lưu trữ với tối đa số lượng phần tử của mảng hoặc tới khi gặp ký tự xuống dòng.
-** fgetc()**	Lấy giá trị tại địa chỉ hiện tại của file, sau đó di chuyển tới địa chỉ tiếp theo. Kiểu trả về là char
- **fread()**	Đọc một số lượng byte được chỉ định từ File .bin

 ### Ghi file
- **fprintf()**	Ghi chuỗi vào File, và có thể thêm danh sách các đối số 
- **fputs()**	Ghi chuỗi vào File
- **fputc()** Ghi một ký tự vào File
- **fwrite()**	Ghi một số byte được chỉ định vào File .bin
- ### Đóng file
Sau khi mở File và không dùng nữa, thì ta cần đóng File để giải phóng tài nguyên và đảm bảo dữ liệu đã được lưu trữ.
```c
fclose(file_name);
```
## 3. Code standards
- Sử dụng tên biến, hằng số, hàm và cấu trúc có ý nghĩa. Tên của chúng nên phản ánh chính xác chức năng và mục đích của chúng.
- Sử dụng các toán tử và hàm thư viện chuẩn của ngôn ngữ để tránh việc viết lại các phép tính hoặc hàm đã có sẵn.
- Sử dụng các lệnh điều kiện và vòng lặp một cách cẩn thận và đảm bảo chúng đúng về mặt logic và hiệu năng.
- Sử dụng comment để giải thích mã của bạn, đặc biệt là những phần mã khó hiểu hoặc dễ bị lỗi.

**Quy tắc về đặt tên**
Sử dụng kiểu đặt tên CamelCase cho biến và hàm:
```c
int numCars = 10;
float totalSales = 1000.0;
void getVehicleInfo() { ... }
```
Sử dụng kiểu đặt tên PascalCase cho các cấu trúc và lớp đối tượng:
```c
struct CarModel { ... };
class SalesReport { ... };
```
Sử dụng chữ hoa cho các hằng số:
```c
const int MAX_NUM_CARS = 100;
const float DEFAULT_SPEED_LIMIT = 60.0;
```
Đặt tên biến theo quy tắc “type + name”:
```c
int iNumCars = 10;
float fSalesTotal = 1000.0;
```
Đặt tên biến trong hàm theo quy tắc “type + name” hoặc “name + type”:
```c
int calculateRevenue(int iNumCars, float fPricePerCar);
void printSalesReport(SalesReport rptSales);
```
Sử dụng tiền tố cho biến để chỉ định mục đích sử dụng của biến:
```c
int g_iNumCars = 10; // biến toàn cục
int s_iSalesTotal = 1000.0; // biến cục bộ tĩnh
```
Đặt tên hàm để thể hiện mục đích và hoạt động của nó:
```c
int calculateRevenue(int iNumCars, float fPricePerCar); // tính doanh thu
void printSalesReport(SalesReport rptSales); // in báo cáo doanh số
```
Đặt tên hàm callback để thể hiện mục đích và cách sử dụng của nó:
```c
void ButtonClickedCallback(void); // callback được gọi khi nút được nhấn
```
Đặt tên enum và các hằng số để thể hiện ý nghĩa của chúng:
```c
enum CarType { SEDAN, SUV, SPORTS };
const int MAX_NUM_SEATS = 8;
```
Đặt tên các file và thư mục để thể hiện nội dung của chúng:
```c
car_model.h // khai báo cấu trúc thông tin xe
sales_report.cpp // mã nguồn tính toán báo cáo doanh số
```
Quy tắc về sử dụng bộ nhớ:

- Không sử dụng con trỏ NULL: Tránh sử dụng con trỏ NULL trong ứng dụng vì nó có thể dẫn đến lỗi runtime hoặc crash hệ thống. Thay vào đó, nên sử dụng con trỏ hợp lệ và kiểm tra điều kiện để đảm bảo rằng chúng được sử dụng một cách an toàn.

- Sử dụng kích thước phù hợp cho kiểu dữ liệu: Khi khai báo biến hoặc cấp phát bộ nhớ cho một đối tượng, cần sử dụng kích thước phù hợp với kiểu dữ liệu. Việc này giúp tiết kiệm bộ nhớ và đảm bảo an toàn khi thao tác với đối tượng đó.

    Ví dụ:
```c
// Khai báo một mảng số nguyên với 10 phần tử
int arr[10];
// Cấp phát bộ nhớ cho một chuỗi ký tự với độ dài 20
char *str = malloc(20 * sizeof(char));
```
Có rất nhiều tiêu chuẩn chưa được đề cập, mọi người có thể [Tham khảo quy tắc các tiêu chuẩn code nhé :) ](https://hala.edu.vn/c-co-ban/cac_quy_tac_ve_dat_ten_theo_tieu_chuan_autosar_c_coding_guidelines/)
