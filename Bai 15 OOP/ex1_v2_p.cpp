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