#include <iostream>
using namespace std;

template <typename T>
auto add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Cộng số nguyên: " << add(3, 5) << endl;       // Kết quả: 8
    cout << "Cộng số thực: " << add(2.5, 4.3) << endl;    // Kết quả: 6.8
    // cout << "Cộng một số nguyên với một số thực: "<< add(1,4.3) << endl;  // Nó sẽ báo lỗi vì hai tham số không cùng kiểu dữ liệu
    return 0;
}