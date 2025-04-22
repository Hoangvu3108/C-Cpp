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

        // // contructor  c1
        // Hinhchunhat() // hàm này được gọi là constructor trùng trên với class và nó có thể nằm ở bất cứ phạm vi nào như public, private, protected
        // {
        //     chieudai = 20;
        //     chieurong = 5;
        // } c1
        
        // // contructor  c2 
        // Hinhchunhat() : chieudai(20), chieurong(51){}
        // // c2
        
        //c3
        Hinhchunhat (double a, double b) // ở đây là constructor có tham số truyền vào phải truyền tham số tại phần object của class
        {
            chieudai = a;
            chieurong = b;
        }

        //c3

        //Hinhchunhat(double a=5, double b=10) // ở đây khi truyền tham số nếu mà không truyền tham số vào thì nó sẽ lấy giá trị mặc định là 5 và 10 
        // {    chieudaia = a; chieurong = b; }
}; 
void Hinhchunhat::display() // ở đây phải có :: vì nó là truy cập tới các member của class vì nó cần phải truy cập tới hàm dientich() và hàm display () nằm trong class
{
    cout << "Dien tich :"  << dientich() << endl;
}

int main (int argc, char const *argv[])
{
    // Hinhchunhat hinh1; // ở đây hinh1 được gọi là object thuộc về class Hinhchunhat
    Hinhchunhat hinh1(10,25), hinh2(10,88); // ở đây hinh1 được gọi là object thuộc về class Hinhchunhat
    hinh1.display(); 
    hinh2.display();
    return 0;
}