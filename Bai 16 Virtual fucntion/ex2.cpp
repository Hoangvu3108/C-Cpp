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
    virtual void display() =0; // Phương thức ảo thuần túy, bắt buộc lớp con phải định nghĩa lại không được khai báo lại
};

class SinhVien : public Doituong {
protected:
    string chuyenNganh;
public:
    void setTen(string name) {
        setName(name);
    }
    void setNganh(string nganh) {
        chuyenNganh = nganh;
    }
    void display() override{ // override để ghi đè phương thức display của lớp cha
        // Doituong::display();
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;
        cout << "Chuyen nganh: " << chuyenNganh << endl;
    }
};

class HocSinh : public Doituong {
protected:
    string lop;
public:
    void setTen(string name) {
        setName(name);
    }
    void setLop(string khoi) {
        lop = khoi;
    }
    void display() override{ // override để ghi đè phương thức display của lớp cha
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;// Ghi đè phương thức display của lớp cha{
        // Doituong::display();
        cout << "Lop: " << lop << endl;
    }
};

int main() {
    SinhVien sv1;
    sv1.setTen("Hoang Long Vu");
    sv1.setNganh("Ky thuat o to");
    // sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setTen("Nguyen Van A");
    hs1.setLop("10A1");
    // hs1.display();

    Doituong *dt1; // vẫn là con trỏ lớp cha nhưng không thể khởi tạo đối tượng lớp cha được vì có phương thức ảo thuần túy

    dt1 = &sv1; // Con trỏ lớp cha trỏ đến đối tượng lớp con
    dt1->display(); // Gọi phương thức display của lớp con SinhVien

    dt1 = &hs1; // Con trỏ lớp cha trỏ đến đối tượng lớp con
    dt1->display(); // Gọi phương thức display của lớp con HocSinh

    cout << endl;

    Doituong *ptr[] = {&sv1, &hs1}; // Mảng con trỏ lớp cha trỏ đến các đối tượng lớp con
    ptr[0]->display(); // Gọi phương thức display của lớp con SinhVien
    ptr[1]->display(); // Gọi phương thức display của lớp con HocSinh

    
    return 0;
}
