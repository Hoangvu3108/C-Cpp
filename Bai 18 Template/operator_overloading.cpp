#include<iostream>

using namespace std;

class Phanso
{
    private:
        int tu;
        int mau;
    public:
        Phanso() : tu(0), mau(1) {} // Default constructor
        Phanso(int t, int m) : tu(t), mau(m) {}
        Phanso operator *(Phanso other)
        {
            Phanso result;
            result.tu = this->tu * other.tu;
            result.mau = this->mau * other.mau;
            return result;
        }
    void display()
    {
        cout <<"Tu: "<< tu << " / "<<"Mau: " << mau << endl;
    }
};
int main()
{
    Phanso p1(1,2);
    Phanso p2(3,4);
    Phanso p3 = p1 * p2; // Gọi toán tử + để cộng hai phân số
    p1.display(); // Hiển thị kết quả
    p2.display(); // Hiển thị kết quả
    p3.display(); // Hiển thị kết quả
    return 0;
}