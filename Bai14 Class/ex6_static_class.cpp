#include<iostream>
#include<string>
using namespace std; 

class Hinhchunhat // có 3 phạm vi truy cập là public, private, protected 
{
    public:
        double chieudai; // được gọi là properties hoặc attributes của class 
        double chieurong;
        static int var;  
}; 
// để cấp địa chỉ cho biến static thì phải khai báo nó ở ngoài class
int Hinhchunhat::var ; // khởi tạo giá trị cho biến static 

int main (int argc, char const *argv[])
{
    Hinhchunhat hinh1, hinh2; // khởi tạo object như khai báo biến
    cout << "Dia chi cua hinh1: " << &hinh1 << endl;
    cout << "Dia chi cua chieu dai hinh 1: " << &hinh1.chieudai << endl;
    cout << "Dia chi cua chieu rong hinh 1: " << &hinh1.chieurong << endl;
    cout << "Dia chi cua var hinh 1: " << &hinh1.var << endl;

    cout << endl;
    cout << "Dia chi cua hinh2: " << &hinh2 << endl;
    cout << "Dia chi cua chieu dai hinh 2: " << &hinh2.chieudai << endl;
    cout << "Dia chi cua chieu rong hinh 2: " << &hinh2.chieurong << endl;
    cout << "Dia chi cua var hinh 2: " << &hinh2.var << endl;
    return 0;
}
// khi khởi tạo object thì 
// khi thấy kêt quả thì sẽ thấy sử dụng chung vùng nhớ  của biến static var 