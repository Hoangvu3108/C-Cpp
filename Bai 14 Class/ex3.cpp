#include<iostream>

using namespace std; 

class Hinhchunhat // có 3 phạm vi truy cập là public, private, protected 
{
    public:
        double chieudai; // được gọi là properties hoặc attributes của class
        double chieurong;

        double dientich() // hàm được gọi là method của class
        {
            return chieudai*chieurong;
        }

        void display (); // cái này cũng gọi là method của class 
}; 
void Hinhchunhat::display() // ở đây phải có :: vì nó là truy cập tới các member của class vì nó cần phải truy cập tới hàm dientich() và hàm display () nằm trong class
{
    cout << "Dien tich :"  << dientich() << endl;
}
// class co the khai bao ham trong class hoac ngoai class
// ham trong class thi co the truy cap truc tiep den cac thanh phan cua class
int main (int argc, char const *argv[])
{
    Hinhchunhat hinh1; // ở đây hinh1 được gọi là object thuộc về class Hinhchunhat  
    hinh1.chieudai = 10;
    hinh1.chieurong = 5; 
    // hinh1.dientich();
    // cout << "Dien tich hinh chu nhat la: " << hinh1.dientich() << endl;
    hinh1.display(); 
    return 0;
}
// object có thể truy cập tất cả khi phạm vi truy cập là public 
// //     hinh1.chieudai = 10;
// hinh1.chieurong = 5; 
// // hinh1.dientich();
// // cout << "Dien tich hinh chu nhat la: " << hinh1.dientich() << endl;
// hinh1.display(); 
// như cậu lệnh trên được gọi là truy cập từ bên ngoài class