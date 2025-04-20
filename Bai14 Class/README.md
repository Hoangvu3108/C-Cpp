# Bài 14: Class
## 1. Định nghĩa 
Trong C++, từ khóa **class** được sử dụng để định nghĩa một lớp là một cáu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan.

## 2. Các từ khóa liên quan 
Các từ khóa như **private**, **public**, và **protected** được gọi chung là phạm vi truy cập. 
**private**: các thành phần riêng tư chỉ có thể truy cập từ bên trong lớp.

**protected**: Các thành phần bảo về tương tự như private, nhưng có thể truy cập từ lớp kế thừa.

**public**: Các thành phần công khai được truy cập từ bên ngoài lớp, hàm thành viên và các phương thức khác có thể định nghĩa tại đây.

**Object**
Được tạo ra từ một class và có đầy đủ các thuộc tính và phương thức mà class đó đã định nghĩa.

**Ví dụ**
```c
#include<iostream>
using namespace std;

class HinhChuNhat()
{
    //Do something
};
int main ()
{
    //Declar object
    HinhChuNhat hinh;
    return 0;
}

```

**Property**(Thuộc tính)
Là các biến thành viên.
Ví dụ:

```c
#include<iostream>

using namespace std;

class HinhChuNhat()
{
public:
    //Properties
    double ChieuDai;
    double ChieuRong;
};
int main ()
{
    HinhChuNhat hinh;
    // assign value to properties
    hinh.ChieuDai =20;
    hinh.ChieuRong =10;
}
```
**Method** (Phương thức)
là các hàm thành viên.
```c
#include<iostream>

using namespace std;

class HinhChuNhat()
{
public:
    //Properties
    double ChieuDai;
    double ChieuRong;
    //Method
    double DienTich()
    {
        return ChieuDai * ChieuRong;
    }
    //Method
    void display();

};
void HinhChuNhat :: display()
{
    cout <<"Dien tich :"  << Dientich() << endl;
}
int main ()
{
    HinhChuNhat hinh;
    // assign value to properties
    hinh.ChieuDai =20;
    hinh.ChieuRong =10;
}
```

**Constructor**
Là method đặc biệt của class.Constructor sẽ có tên trùng với tên của class.
```c
#include<iostream>

using namespace std;

class HinhChuNhat()
{
public:
    //Properties
    double ChieuDai;
    double ChieuRong;
    //Method
    double DienTich()
    {
        return ChieuDai * ChieuRong;
    }
    //Method
    void display();
    HinhChuNhat() {
        ChieuDai = 20;
        ChieuRong = 30;
    }

};
```
**Contructor có tham số truyền vào **
Ví dụ :


```c
#include<iostream>

using namespace std;

class HinhChuNhat()
{
public:
    //Properties
    double ChieuDai;
    double ChieuRong;
    //Method
    double DienTich()
    {
        return ChieuDai * ChieuRong;
    }
    //Method
    void display();

    HinhChuNhat(int a. int b)
    {
        ChieuRong =a;
        ChieuDai =b ;
    }

};
```

**Constructor có tham số truyền vào còn có cách viết khác:**
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    double chieuDai;  
    double chieuRong; 

    // Constructor with default parameters
    HinhChuNhat(int a = 3, int b = 5) {
        chieuDai = a;
        chieuRong = b;
    }
    // Do something ...
};

int main() {
    // This will use the default values: chieuDai = 3, chieuRong = 5
    HinhChuNhat hinh1;

     // This will use the provided values: chieuDai = 10, chieuRong = 20
    HinhChuNhat hinh2(10, 20);
    return 0;
}
```
**Destructor**
Là method đặc biệt của class.
Được gọi tự động khi object được giải phóng
Mục đính chính của destructor là giải phóng tài nguyên
Destructor có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên.
```c
#include<iostream>
using namespace std;

class HinhChuNhat{
public : 
    string name;
    
    // Constructor 
    HinhChuNhat (string n) :name (n)
    {
        cout << "Khoi tao project" << name << end;
    }
    // Destructor
    ~HinhChuNhat()
    {
        cout << "Destructor :" << name <<endl; 
    }
};
```

```c
#include<iostream>
#include<string>
using namespace std; 

class Hinhchunhat // có 3 phạm vi truy cập là public, private, protected 
{
    public:
        string name;
        double chieudai; // được gọi là properties hoặc attributes của class
        double chieurong;

        double dientich() // hàm được gọi là method của class
        {
            return chieudai*chieurong;
        }

        void display ();

        Hinhchunhat (string name) // ở đây là constructor có tham số truyền vào phải truyền tham số tại phần object của class
        {
            Hinhchunhat::name = name;
            cout << "Khoi tai doi tuong " << Hinhchunhat::name << endl;
        }

      
        ~Hinhchunhat()
        {
            cout << "Huy doi tuong " << Hinhchunhat::name << endl;
        }
}; 
void Hinhchunhat::display() // ở đây phải có :: vì nó là truy cập tới các member của class vì nó cần phải truy cập tới hàm dientich() và hàm display () nằm trong class
{
    cout << "Dien tich :"  << dientich() << endl;
}
void test ()
{
    Hinhchunhat hinh3("Hoang Long Vu");
    Hinhchunhat hinh4("Hoang Long Vu 2");
}
int main (int argc, char const *argv[])
{
    test();
    return 0;
}
// bản chất cái biến Hinhchunhat hinh3("Hoang Long Vu");  là một cái biến cục bộ mà biến cục bộ thì sẽ lưu ở phân vùng stack và khi kết thúc cái hàm này nó sẽ bị thu hồi và hoạt động theo cách LIFO
````
**Static member**
Bao gồm biến tĩnh (stactics properties) và hàm tĩnh (static functions)
Tất cả các object của class được dùng cchung địa chỉ và giá trị.

**Ví dụ**
```c
#include<iostream>
#include<string>
using namespace std; 

class Hinhchunhat // có 3 phạm vi truy cập là public, private, protected 
{
    public:
        double chieudai; // được gọi là properties hoặc attributes của class 
        double chieurong;
        static int var;  
}; 
// để cấp địa chỉ cho biến static thì phải khai báo nó ở ngoài class
int Hinhchunhat::var ; // khởi tạo giá trị cho biến static 

int main (int argc, char const *argv[])
{
    Hinhchunhat hinh1, hinh2; // khởi tạo object như khai báo biến
    cout << "Dia chi cua hinh1: " << &hinh1 << endl;
    cout << "Dia chi cua chieu dai hinh 1: " << &hinh1.chieudai << endl;
    cout << "Dia chi cua chieu rong hinh 1: " << &hinh1.chieurong << endl;
    cout << "Dia chi cua var hinh 1: " << &hinh1.var << endl;

    cout << endl;
    cout << "Dia chi cua hinh2: " << &hinh2 << endl;
    cout << "Dia chi cua chieu dai hinh 2: " << &hinh2.chieudai << endl;
    cout << "Dia chi cua chieu rong hinh 2: " << &hinh2.chieurong << endl;
    cout << "Dia chi cua var hinh 2: " << &hinh2.var << endl;
    return 0;
}
// khi khởi tạo object thì 
// khi thấy kêt quả thì sẽ thấy sử dụng chung vùng nhớ  của biến static var 
```