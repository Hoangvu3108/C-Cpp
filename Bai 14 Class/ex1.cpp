#include<iostream>
using namespace std;

class HinhChuNhat
{
    public:
        double chieudai;
        double chieurong;

        double dientich()
        {
            return chieudai*chieurong;
        }

        void display ();
        // {
        //     cout << "Dien tich :"  << h1.dientich() << endl;
        // }
        // HinhChuNhat ()
        // {
        //     chieudai = 10;
        //     chieurong = 5;
        // }
        HinhChuNhat(int a ,int b)
        {
            chieudai = a;
            chieurong = b;
        }
};

void HinhChuNhat::display()
{
    cout << "Dien tich :"  << dientich() << endl;
}
int main (int argc, char const *argv[])
{
    HinhChuNhat h1(5,6), h2(10,5);
    // h1.chieudai = 10.5;
    // h1.chieurong = 5.5;
    h1.dientich();
    h1.display();
    h2.display();
    return 0;
}