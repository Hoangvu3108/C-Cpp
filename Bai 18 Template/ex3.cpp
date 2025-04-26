#include<iostream>
using namespace std;

template <typename TypeA, typename TypeB>
auto add(TypeA a, TypeB b) {
    return a + b;
}

int main ()
{
    cout << "Sum: "<< add(3, 5) << endl;       // Kết quả: 8
    cout << "Sum: "<< add(2.5, 4.3) << endl;    // Kết quả: 6.8
    cout << "Sum: "<< add(1,4.3) << endl;  // Nó sẽ báo lỗi vì hai tham số không cùng kiểu dữ liệu
}