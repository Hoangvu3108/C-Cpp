// #include<iostream>

// using namespace std;

// class Example {
//     Example ()
//     {
//         cout << "Constructor called" << endl;
//     }
//     ~Example ()
//     {
//         cout << "Destructor called" << endl;
//     }
// };

// int main()
// {
//     Example obj;
//     return 0;
// }
#include <iostream>
using namespace std;

class Example {
public:
    // Constructor - Được gọi khi đối tượng được tạo
    Example() {
        cout << "Object created!" << endl;
    }

    // Destructor - Được gọi khi đối tượng bị hủy
    ~Example() {
        cout << "Object destroyed!" << endl;
    }
};

int main() {
    Example obj; // Khi kết thúc phạm vi, destructor sẽ tự động được gọi
    cout << "Inside main function" << endl;
    
    return 0; // Khi chương trình kết thúc, obj bị hủy và destructor được gọi
}
