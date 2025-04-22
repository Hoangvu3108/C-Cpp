#include<iostream>
#include <string>

using namespace std;


class Doituong{
   protected: 
       string ten;
       int id;
    public:
        Doituong(){
            static int ID=20210001;
            id =ID;
            ID++;
        }
        void setName(string name){
            ten=name;
        }
        void display(){
            cout << "Ten:" << ten << endl;
            cout << "ID:" << id << endl;  
        }
};
class SinhVien : public Doituong{ 

   private:
       string chuyenNganh;
    public :
    void display(){
        cout << "Ten:" << ten << endl;
        cout << "ID:" << id << endl;
        cout << "Chuyen nganh:" << chuyenNganh << endl;  
    }
    void setNganh(string Nganh){
        chuyenNganh=Nganh;
    }
};
class HocSinh : public Doituong{
   private:
       string lop;
    public :
    void display(){
        cout << "Ten:" << ten << endl;
        cout << "ID:" << id << endl;
        cout << "Lop:" << lop << endl;  
    }
    void setLop(string khoi){
        lop=khoi;
    }
};
class GiaoVien : public Doituong{
   public:
       string monHoc;
};


int main (int argc, char const *argv[])
{
   SinhVien sv1;

   sv1.setName("Hoang Long Vu");
   sv1.setNganh("Ky thuat o to");
    sv1.display();

    cout << endl;   
    
    HocSinh hs1;
    hs1.setName("Nguyen Van A");
    hs1.setLop("10A1");
    hs1.display();


}

//  đây là kế thừa public 