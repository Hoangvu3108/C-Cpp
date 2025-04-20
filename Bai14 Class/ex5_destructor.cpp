#include<iostream>
#include<string>
using namespace std; 

class Hinhchunhat // có 3 phạm vi truy cập là public, private, protected 
{
    public:
        string name;
        double chieudai; // được gọi là properties hoặc attributes của class
        double chieurong;

        double dientich() // hàm được gọi là method của class
        {
            return chieudai*chieurong;
        }

        void display ();

        Hinhchunhat (string name) // ở đây là constructor có tham số truyền vào phải truyền tham số tại phần object của class
        {
            Hinhchunhat::name = name;
            cout << "Khoi tai doi tuong " << Hinhchunhat::name << endl;
        }

      
        ~Hinhchunhat()
        {
            cout << "Huy doi tuong " << Hinhchunhat::name << endl;
        }
}; 
void Hinhchunhat::display() // ở đây phải có :: vì nó là truy cập tới các member của class vì nó cần phải truy cập tới hàm dientich() và hàm display () nằm trong class
{
    cout << "Dien tich :"  << dientich() << endl;
}
void test ()
{
    Hinhchunhat hinh3("Hoang Long Vu");
    Hinhchunhat hinh4("Hoang Long Vu 2");
}
int main (int argc, char const *argv[])
{
    test();
    return 0;
}
// bản chất cái biến Hinhchunhat hinh3("Hoang Long Vu");  là một cái biến cục bộ mà biến cục bộ thì sẽ lưu ở phân vùng stack và khi kết thúc cái hàm này nó sẽ bị thu hồi và hoạt động theo cách LIFO