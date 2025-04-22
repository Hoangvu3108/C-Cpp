#include<iostream>
#include<string>
using namespace std;

class SinhVien{

    public:
        string ten;
        int id;
        string chuyenNganh;

        SinhVien(string ten, string chuyenNganh);
};
SinhVien ::SinhVien(string ten, string chuyenNganh){  // Constructor
    static int ID=20210001;
    SinhVien::id=ID;
    ID++;               // Tự động tăng ID lên mỗi khi khởi tạo một object
    SinhVien::ten=ten;
    SinhVien::chuyenNganh=chuyenNganh;

}
int main (int argc, char const *argv[])

{
    
    SinhVien sv1("Hoang Long Vu", "Ky thuat o to");
    sv1.ten="Hoang Van A";
    // sv1.id=20217599;
    sv1.chuyenNganh="Cong nghe thong tin";
    cout << "Sinh vien 1: " << sv1.ten << " - " << sv1.id << " - " << sv1.chuyenNganh << endl;

    SinhVien sv2("Nguyen Van B", "Cong nghe thong tin");
    cout << "Sinh vien 2: " << sv2.ten << " - " << sv2.id << " - " << sv2.chuyenNganh << endl;
    return 0;
}
// nó không quan tâm đến chuỗi này đúng hay sai như thế nào bởi đây là chuỗi khi bạn nhập kí tự bất kì vào chuồi đuề có thể đưuọc 
// để tránh việc truyền vào các kí tự không hợp lệ thì ta sử dụng private để bảo vệ các thuộc tính của lớp và không cho phép truy cập từ bên ngoài
// và sử dụng các phương thức setter và getter để truy cập vào các thuộc tính của lớp.