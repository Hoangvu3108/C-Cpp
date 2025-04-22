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