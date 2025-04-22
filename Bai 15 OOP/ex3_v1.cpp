#include <iostream>
#include <string>

using namespace std;

class Doituong {
protected:
    string ten;
    int id;
public:
    virtual void setName(string name) {
        ten = name;
    }
    virtual void display() const {
        cout << "Ten: " << ten << endl;
        cout << "ID: " << id << endl;
    }
};

class SinhVien : public Doituong {
private:
    string chuyenNganh;
    static int IDGenerator; // Static ID generator for SinhVien
public:
    SinhVien() {
        id = IDGenerator++;
    }
    void setNganh(string nganh) {
        chuyenNganh = nganh;
    }
    void display() const override {
        Doituong::display();
        cout << "Chuyen nganh: " << chuyenNganh << endl;
    }
};
int SinhVien::IDGenerator = 20210001; // Initialize static ID generator

class HocSinh : public Doituong {
private:
    string lop;
    static int IDGenerator; // Static ID generator for HocSinh
public:
    HocSinh() {
        id = IDGenerator++;
    }
    void setLop(string khoi) {
        lop = khoi;
    }
    void display() const override {
        Doituong::display();
        cout << "Lop: " << lop << endl;
    }
};
int HocSinh::IDGenerator = 1; // Initialize static ID generator

class GiaoVien : public Doituong {
private:
    string monHoc;
    static int IDGenerator; // Static ID generator for GiaoVien
public:
    GiaoVien() {
        id = IDGenerator++;
    }
    void setMonHoc(string mon) {
        monHoc = mon;
    }
    void display() const override {
        Doituong::display();
        cout << "Mon hoc: " << monHoc << endl;
    }
};
int GiaoVien::IDGenerator = 1; // Initialize static ID generator

int main() {
    SinhVien sv1;
    sv1.setName("Hoang Long Vu");
    sv1.setNganh("Ky thuat o to");
    sv1.display();
    
    cout << endl;
    SinhVien sv2;
    sv2.setName("Nguyen Van A");
    sv2.setNganh("Cong nghe thong tin");
    sv2.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Nguyen Van A");
    hs1.setLop("10A1");
    hs1.display();

    cout << endl;
    HocSinh hs2;
    hs2.setName("Nguyen Van B");
    hs2.setLop("10A2");
    hs2.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Tran Thi B");
    gv1.setMonHoc("Toan");
    gv1.display();

    GiaoVien gv2;
    gv2.setName("Le Van C");
    gv2.setMonHoc("Ly");
    gv2.display();

    return 0;
}
