#include<iostream>
#include<string>

using namespace std;
class A{
    public:
        void displayA(){
            cout << "This is class A" << endl;
        }
};
class B: virtual public A{
    public:
        void displayB(){
            cout << "This is class B" << endl;
        }
};
class C: virtual public A, virtual public B{
    public:
        void displayC(){
            cout << "This is class C" << endl;
        }
};
class D: virtual public C{
    public:
        void displayD(){
            cout << "This is class D" << endl;
        }
};
int main ()
{
    D objD;
    objD.A::displayA(); // Gọi phương thức displayA() từ lớp A
    objD.B::displayA(); // Gọi phương thức displayA() từ lớp B
    objD.C::displayA(); // Gọi phương thức displayA() từ lớp C
    objD.C::displayB(); // Gọi phương thức displayB() từ lớp C
    objD.C::displayC(); // Gọi phương thức displayC() từ lớp C
    objD.displayC(); // Gọi phương thức displayC() từ lớp C
    objD.displayD(); // Gọi phương thức displayD() từ lớp D
    objD.displayA(); // Gọi phương thức displayA() từ lớp D phiên bản duy nhất trong class D

}
// Để khắc phục vấn đề khi có nhiều class cha kế thừa từ một class cha khác, ta sử dụng từ khóa virtual trong khai báo lớp con.
// sử dụng từ khóa virtual trong khai báo lớp con để đảm bảo rằng chỉ có một bản sao của lớp cha được tạo ra trong cây kế thừa.