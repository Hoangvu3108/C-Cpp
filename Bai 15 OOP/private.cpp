// #include<iostream>
// #include<string>
// #include<regex>
// using namespace std;

// class SinhVien{

//     private:
//         string ten;
//         int id;
//         string chuyenNganh;
//     public :
//         SinhVien(string ten, string chuyenNganh); // những cái method trong hàm private không thể truy cập được từ bên ngoài 
// };// cái những method trong public thì có thể truy cập đến thằng private

// // CONSTRUCTOR  
// SinhVien ::SinhVien(string ten, string chuyenNganh){  // Constructor
//     static int ID=20210001;
//     SinhVien::id=ID;
//     ID++
//     // // kiểm tra lỗi tên tránh kí tự đặc biệt                // Tự động tăng I  D lên mỗi khi khởi tạo một object
//     // SinhVien::ten=ten;
//     // SinhVien::chuyenNganh=chuyenNganh;
//      // Kiểm tra lỗi tên tránh kí tự đặc biệt
//      regex pattern("^[A-Za-zÀ-ỹ\\s]+$");  // Chỉ cho phép chữ cái và khoảng trắng
//      while (!regex_match(ten, pattern)) {
//         cout << "Ten khong hop le! Vui long nhap lai (khong chua ky tu dac biet): ";
//         getline(cin, ten);
//         }
// int main (int argc, char const *argv[])

// {
    
//     SinhVien sv1("Hoang Long Vu", "Ky thuat o to");
//     sv1.ten="Hoang Van A";
//     // sv1.id=20217599;
//     sv1.chuyenNganh="Cong nghe thong tin";
//     cout << "Sinh vien 1: " << sv1.ten << " - " << sv1.id << " - " << sv1.chuyenNganh << endl;

//     SinhVien sv2("Nguyen Van B", "Cong nghe thong tin");
//     cout << "Sinh vien 2: " << sv2.ten << " - " << sv2.id << " - " << sv2.chuyenNganh << endl;
//     return 0;
// }
// // nó không quan tâm đến chuỗi này đúng hay sai như thế nào bởi đây là chuỗi khi bạn nhập kí tự bất kì vào chuồi đuề có thể đưuọc 

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class SinhVien {
private:
    string ten;
    int id;
    string chuyenNganh;
public:
    SinhVien(string ten, string chuyenNganh);
};

// Constructor
SinhVien::SinhVien(string ten, string chuyenNganh) {
    static int ID = 20210001;
    this->id = ID;
    ID++;  // Tăng ID tự động mỗi khi khởi tạo object

    // Kiểm tra lỗi tên tránh kí tự đặc biệt
    regex pattern("^[A-Za-zÀ-ỹ\\s]+$");  // Chỉ cho phép chữ cái và khoảng trắng

    while (!regex_match(ten, pattern)) {
        cout << "Ten khong hop le! Vui long nhap lai (khong chua ky tu dac biet): ";
        getline(cin, ten);
    }

    this->ten = ten;
    this->chuyenNganh = chuyenNganh;
}

// Hàm main để kiểm tra
int main() {
    string ten, chuyenNganh;
    cout << "Nhap ten sinh vien: ";
    getline(cin, ten);
    cout << "Nhap chuyen nganh: ";
    getline(cin, chuyenNganh);

    SinhVien sv(ten, chuyenNganh);
    cout << "Sinh vien duoc tao thanh cong!" << endl;

    return 0;
}
  // Tính đóng gói trong OOP là ẩn đi các property người dùng và ta sẽ khai báo các property ở quyền truy cập private 
  // muốn đọc hoặc ghi thì ta sẽ dùng truy cập gián tiếp thông qua các method getter và setter ở quyền truy cập public