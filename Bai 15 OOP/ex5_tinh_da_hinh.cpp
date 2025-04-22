// ở C++ nó hỗ trợ viết nhiều hàm giống tên và những hàm trả về 
#include<iostream>
#include <string>

using namespace std;

class Tinhtoan{
    private :
        int a;
        int b;
    public:
        int tong(int a,int b)
        {
            return a+b;
        }
        double tong (int a, int b, int c)
        {
            return a+b+c;
        }
        double tong(int a, double b)
        {
            return a+b;
        }
}; 
int main ()
{
    Tinhtoan th1,th2,th3;
    cout << th1.tong(1,2) << endl;
    cout << th2.tong(1,2,3) << endl;
    cout << th3.tong(1,2.5) << endl;
     
    return 0;
}
// một method có nhiều input parameter khác nhau thì nó sẽ trả về giá trị khác nhau thì đây được gọi là tính đa hình 
// Đây là bài toán đa hình tại thời điểm biên dịch
// cái này gọi là overload method 