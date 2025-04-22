// #include <iostream>
// #include <string>
// #include <regex>

// using namespace std;

// class SinhVien {
// private:
//     string ten;
//     int id;
//     string chuyenNganh;
//     double gpa;
// public:
//     SinhVien(string ten, string chuyenNganh);
//     string getName();
//     int getId();

//     // Setter method
//     void setGPA(double newGPA);
// };
// // Getter method
// string SinhVien::getName() {
//     return ten;
// }
// void SinhVien::setGPA(double newGPA) {
//     SinhVien::gpa=newGPA
// }

// // Constructor
// SinhVien::SinhVien(string ten, string chuyenNganh) {
//     static int ID = 20210001;
//     this->id = ID;
//     ID++;  // Tăng ID tự động mỗi khi khởi tạo object

    
// }

// // Hàm main để kiểm tra
// int main() {
//     string ten, chuyenNganh;
//     cout << "Nhap ten sinh vien: ";
//     getline(cin, ten);
//     cout << "Nhap chuyen nganh: ";
//     getline(cin, chuyenNganh);

//     SinhVien sv(ten, chuyenNganh);
//     cout << "Sinh vien duoc tao thanh cong!" << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

class Car {
private:
    int speed;

public:
    // Setter
    void setSpeed(int s) {
        if (s >= 0)
            speed = s;
        else
            cout << "Speed cannot be negative!" << endl;
    }

    // Getter
    int getSpeed() {
        return speed;
    }
};

int main() {
    Car myCar;
    myCar.setSpeed(100);
    cout << "Car speed: " << myCar.getSpeed() << " km/h" << endl;

    return 0;
}
