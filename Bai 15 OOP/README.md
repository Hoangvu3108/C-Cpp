# OOP 
## 1. Tính đóng gói 
Tính đóng gói là ẩn đi các property "mật" khỏi người dùng.
Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập privare (tức là không thể truy cập trực tiếp tới các property này.)
**Ví dụ**:
```c
class Sinhvien {
    private :
    // tính đóng gói là ẩn đi các property
    string name;
    int id;
}
```

**Setter and Getter Method**
- **Getter** được sử dụng để lấy giá trị của một thuộc tính property.
- **Setter** được sử dụng để đặt, thay đổi giá trị và kiểm tra tính hợp lệ của property.
**Ví dụ**

```c
#include<iostream>
#include<string>
using namespace std;

class SinhVien{

    private:
        string ten;
        int id;
        string chuyenNganh; 
        double gpa;
    // những property này không thể truy cập từ bên ngoài lớp 
        public:
        // Constructor
        // Constructor là một hàm đặc biệt được gọi khi một đối tượng của lớp được tạo ra.
        SinhVien(string ten, string chuyenNganh);
        // getter and setter method
        string getName();   // getter method dùng để lấy giá trị của thuộc tính ten
        int getID(); // getter method dùng để lấy giá trị của thuộc tính id
        //setter method dùng để lấy giá trị của thuộc tính chuyenNganh
        void  setGPA(double NewGPA);
        string getChuyenNganh();

};
string SinhVien::getName()
{
    return ten;
}
int SinhVien::getID()
{
    return id;
}

void SinhVien::setGPA(double NewGPA)
{
    SinhVien::gpa=NewGPA;

}
string SinhVien::getChuyenNganh()
{
    return chuyenNganh;
}
SinhVien ::SinhVien(string ten, string chuyenNganh){  // Constructor
    static int ID=20210001;
    SinhVien::id=ID;
    ID++;               // Tự động tăng ID lên mỗi khi khởi tạo một object
    // Kiểm tra lỗi ten và chuyenNganh có hợp lệ không
    if (ten.empty() || chuyenNganh.empty()) {
        cout << "Ten va chuyen nganh khong duoc de trong!" << endl;
        return;
    }
    SinhVien::ten=ten;
    SinhVien::chuyenNganh=chuyenNganh;

}
int main (int argc, char const *argv[])

{
    
    SinhVien sv1("Hoang Long Vu", "Ky thuat o to");
    cout << "Sinh vien 1: " << sv1.getName() << " - " << sv1.getID() << " - " << sv1.getChuyenNganh() << endl;

    SinhVien sv2("Nguyen Van B", "Cong nghe thong tin");
    cout << "Sinh vien 2: " << sv2.getName() << " - " << sv2.getID() << " - " << sv2.getChuyenNganh() << endl;
    return 0;
}  
```

## 2. Tính kế thừa (Inheritance)
Tính kế thừa là khả nặng sử dụng lại các proprety và method của một classs khác. 
Trong tính kế thừa, ta chia làm hai loại class: Class cha(base class) và class con (subclass)
Để kế thừa từ class khác thì ta dùng thêm kí tự : và tên class đó 
**Ví dụ**
```c
class SinhVien : public Doituong{}
```
Có 3 kiểu kế thừa đó là :
- Kế thừa Public
- Kế thừa Private
- Kế thừa Protected
Những property và method được kết thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.

**Kế thừa public**
- Các member public của class cha vẫn là public trong class con 
- Các member protected của class cha vẫn sẽ là protected trong class con và những phần về properties hay method của Class cha ở phạm vi public sẽ thành  protected
- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể truy cập gián tiếp qua các phương thức public hoặc protected của class cha .
**Ví dụ**
```c
#include<iostream>
#include <string>

using namespace std;

// có 3 loại kế thừa đó là kế thừa private, kế thừa public, kế thừa protected
class Doituong{
    protected: // thuộc tính này không thể truy cập từ bên ngoài lớp 
       string ten;
       int id;
    public :
        Doituong()
        {
            static int ID= 1;
            id=ID;
            ID++;               // Tự động tăng ID lên mỗi khi khởi tạo một object
        }
        void setName(string _name){
            ten=_name;
        }
        void display(){
            cout << "Ten: " << ten << endl;
            cout << "ID: " << id << endl;
        }
};
class SinhVien : public Doituong{ // kế thừa từ lớp Doituong 
   // đây gọi là lớp con và đối tượng là lớp cha
   private:
       string chuyenNganh;
    public:
       void display(){ // override phương thức display của lớp cha
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;
        cout << "Chuyen nganh: " << chuyenNganh << endl;
    }
       void setChuyenNganh(string _chuyenNganh){
           chuyenNganh=_chuyenNganh;
       }
};
class HocSinh : public Doituong{
   public:
       string lop;

};
class GiaoVien : public Doituong{
   public:
       string monHoc;
};
// khi đã kế thừa rồi thì không cần khai báo các biến trong lớp cha và chỉ  cần kế thừa thôi bằng cách : doituong
int main (int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Hoang Long Vu");
    sv1.setChuyenNganh("Ky thuat o to"); // ở đây setChuyenNgang () hoàn toàn khác với setChuyenNganh()= "Ky thuat o to" 
    sv1.display();
}
```
**Kế thừa protected**
Các member trong phạm vi public, protected của class cha sẽ là protected trong class con. 
Các member trong phạm vi private thì không thể truy cập từ các class con nhưng có thể truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
**Kế thừa private**
Các member public, protected của class cha sẽ trở thành private trong class.
Các member private của class cha không thể truy cập từ các class ccon nhưng có thể truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
```c
#include <iostream>
using namespace std;

// Class cha
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
    // public method, truy cập private gián tiếp!
    void accessPrivate() {
        breathe();
    }

protected:
    void sleep() {
        cout << "Animal is sleeping" << endl;
    }

private:
    void breathe() {
        cout << "Animal is breathing" << endl;
    }
};

// Class con
class Dog : public Animal {
public:
    void accessProtected() {
        // sleep() truy cập thoải mái ở trong class con.
        sleep();  
    }
};

int main() {
    Dog myDog;
    // eat() ở class cha là public ở class con là public, eat() truy cập ở đâu cũng được.
    myDog.eat(); 
    // sleep() ở class cha là protected ở class con là protected, sleep() truy cập qua phương thức public của class con.
    myDog.accessProtected();
    // breathe() ở class cha là private, chỉ truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
    myDog.accessPrivate();    
}
```

**Ghi đềm hàm** (Function overriding)
Điều này xảy ra khi có một class con định nghĩa lại một method đã được định nghĩa trong class cha.
Method mới trong class con phải có cùng tên, kiểu trả về và danh sách tham số với method của class cha. 
Method mới sẽ thay thế method của class khi được gọi từ một object của class con.
```c
#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Some generic sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Function overriding
    void sound() {
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog myDog;  
    myDog.sound(); 
    // Gọi method sound() của Dog, output: "Woof!"
}
```
**Tính đa hình**
Tính đa hình có nghĩa là nhiều dạng có thể viết được nhiều hàm và nó căn cứ vào tham số truyền vào(input parameter) để nó tính toán và thực hiện lệnh thì nó sẽ tra tham số đầu vào 
```c
// ở C++ nó hỗ trợ viết nhiều hàm giống tên và những hàm trả về 
#include<iostream>
#include <string>

using namespace std;

class Tinhtoan{
    private :
        int a;
        int b;
    public:
        int tong(int a,int b)
        {
            return a+b;
        }
        double tong (int a, int b, int c)
        {
            return a+b+c;
        }
        double tong(int a, double b)
        {
            return a+b;
        }
}; 
int main ()
{
    Tinhtoan th1,th2,th3;
    cout << th1.tong(1,2) << endl;
    cout << th2.tong(1,2,3) << endl;
    cout << th3.tong(1,2.5) << endl;
     
    return 0;
}
// một method có nhiều input parameter khác nhau thì nó sẽ trả về giá trị khác nhau thì đây được gọi là tính đa hình 
// Đây là bài toán đa hình tại thời điểm biên dịch
// cái này gọi là overload method 
```
**Đa hình thời điểm biên dịch(Compile-time Polymorphism)**
Đa hình tại thời điểm biên dịch được sử dụng bằng cách nạp chồng hàm (Function overloading) hoặc nạp chồng toán tử (Operator overloading).

Tính đa hình này được xác định trong quá trình biên dịch, nghĩa là compiler quyết định phiên bản hàm nào sẽ được gọi.

Function overloading: cung cấp nhiều định nghĩa cho một function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.

## 4. Tính trừu tượng(Abstraction)
Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.

Nó có sự tương đồng với tính đóng gói nhưng tính đóng gói là ẩn đi các property còn tính trừu tượng là ẩn đi các method hay quá trình tính toán.
```c
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GiaiPhuongTrinh{
    private:
        // Tính đóng gói-ẩn các property	
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;

        // Tính trừu tượng-ẩn các method
        void tinhNghiem(){	
            delta = b*b - 4*a*c;
            if (delta < 0){
                delta = -1;
            }
            else if (delta == 0){
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0){
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
       
    public:
        // Chỉ show ra phần sử dụng đơn giản cho user
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();

};

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult(){
    tinhNghiem();
    if (delta == -1){
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0){
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0){
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
}
int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();
  return 0;
}
```