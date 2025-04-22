// #include<iostream>
// #include <string>

// using namespace std;


// class Doituong{
//    protected: 
//        string ten;
//        int id;
//     public:
//         Doituong(){
//             static int ID=20210001;
//             id =ID;
//             ID++;
//         }
//         void setName(string name){
//             Doituong::ten=name;
//         }
//         void display(){
//             cout << "Ten:" << Doituong::ten << endl;
//             cout << "ID:" << Doituong::id << endl;  
//         }
// };
// class SinhVien : protected Doituong{ 

//    protected:
//        string chuyenNganh;
//     public :
//         void display(){
//             cout << "Ten:" << Doituong::ten << endl;
//             cout << "ID:" << Doituong::id << endl;
//             cout << "Chuyen nganh:" << chuyenNganh << endl;  
//         }
//         void setNganh(string Nganh){
//         chuyenNganh=Nganh;
// };
// class HocSinh : protected Doituong{
//    protected:
//        string lop;
//     public:
//             void display(){
//             cout << "Ten:" <<Doituong::ten << endl;
//             cout << "ID:" << Doituong::id << endl;
//             cout << "Lop:" << lop << endl;  
//     }
//     void setLop(string khoi){
//         lop=khoi;
//     }
// };
// class GiaoVien : protected Doituong{
//    protected:
//        string monHoc;
// };


// int main (int argc, char const *argv[])
// {
//    SinhVien sv1;

//     sv1.setName("Hoang Long Vu");
//     sv1.setNganh("Ky thuat o to");
//     sv1.display();

//     cout << endl;   
    
//     HocSinh hs1;
//     hs1.setName("Nguyen Van A");
//     hs1.setLop("10A1");
//     hs1.display();


// }

// //  đây là kế thừa protected khi kế thừa protected thì vẫn giữ nguyên protected tuy nhiên khi public ở cha chuyển sang con thì phải là protected 
#include <iostream>
#include <string>

using namespace std;

class Doituong {
protected:
    string ten;
    int id;
public:
    Doituong() {
        static int ID = 20210001;
        id = ID;
        ID++;
    }
    void setName(string name) {
        ten = name;
    }
    void display() {
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;
    }
};

class SinhVien : protected Doituong {
protected:
    string chuyenNganh;
public:
    void setTen(string name) {
        setName(name);
    }
    void setNganh(string nganh) {
        chuyenNganh = nganh;
    }
    void display() {
        Doituong::display();
        cout << "Chuyen nganh: " << chuyenNganh << endl;
    }
};

class HocSinh : protected Doituong {
protected:
    string lop;
public:
    void setTen(string name) {
        setName(name);
    }
    void setLop(string khoi) {
        lop = khoi;
    }
    void display() {
        Doituong::display();
        cout << "Lop: " << lop << endl;
    }
};

int main() {
    SinhVien sv1;
    sv1.setTen("Hoang Long Vu");
    sv1.setNganh("Ky thuat o to");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setTen("Nguyen Van A");
    hs1.setLop("10A1");
    hs1.display();

    return 0;
}
// Ví dụ trên là kế thừa protected, khi kế thừa protected thì các thuộc tính và phương thức protected của lớp cha sẽ trở thành protected của lớp con.

// có nghĩa là các thành viên này chỉ có thể được truy cập từ bên trong lớp dẫn xuất hoặc các lớp dẫn xuất tiếp theo nhưng không thế tiếp tục trước tiếp từ bên ngoài (như trong hàm main) 
// private chỉ có giá trong class đối tượng và  các class con không thể kế thừa và truy cập được  
//  kế thừa thừa class , ta dùng ký tự ":"