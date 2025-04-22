 #include<iostream>
 #include <string>

using namespace std;

// có 3 loại kế thừa đó là kế thừa private, kế thừa public, kế thừa protected
class Doituong{
    public: 
        string ten;
        int id;
};
class SinhVien : public Doituong{ // kế thừa từ lớp Doituong 
    // đây gọi là lớp con và đối tượng là lớp cha
    public:
        string chuyenNganh;

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

    sv1.ten="Hoang Long Vu";
    sv1.id=20217599;
    sv1.chuyenNganh="Ky thuat o to";
    cout << "Sinh vien 1: " << sv1.ten << " - " << sv1.id << " - " << sv1.chuyenNganh << endl;

    HocSinh hs1;
    hs1.ten= "Nguyen Van A";
    hs1.id=1;
    hs1.lop="12A1";
    cout << "Hoc Sinh 1: " << hs1.ten << "-" << hs1.id << "-" << hs1.lop<< endl;
    
    GiaoVien gv1;
    gv1.ten="Nguyen Van B";
    gv1.id=1;
    gv1.monHoc="Toan";
    cout << "Giao Vien 1: " <<gv1.ten << "-" << gv1.id << "-" << gv1.monHoc<< endl;

    SinhVien sv2;
    sv2.ten="Hoang Nhat Minh";
    sv2.id=202175600;
    sv2.chuyenNganh="Ky thuat o to";
    cout << "Sinh vien 2: " << sv2.ten << " - " << sv2.id << " - " << sv2.chuyenNganh << endl;

    HocSinh hs2;
    hs2.ten= "Nguyen Van AB";
    hs2.id=2;
    hs2.lop="12A1";
    cout << "Hoc Sinh 2: " << hs2.ten << "-" << hs2.id << "-" << hs2.lop<< endl;
    
    GiaoVien gv2;
    gv2.ten="Nguyen Van BC";
    gv2.id=2;
    gv2.monHoc="Tieng Anh";
    cout << "Giao Vien 2: " <<gv2.ten << "-" << gv2.id << "-" << gv2.monHoc<< endl;
    // kế thừa public thì các thuộc tính của lớp cha sẽ được kế thừa sang lớp con và có thể truy cập từ bên ngoài lớp con
}
// Đây là kế thừa public
// ở đây chỉ là ví dụ thôi còn thực tế thì không nên khai báo như trên bởi vì khi khai báo như trên thì sẽ dễ bị thay đổi dữ liệu ở ngoài lớp

