#include <iostream>
#include <string>

using namespace std;
class A {
    public:
        void displayA() {
            std::cout << "This is class A" << std::endl;
        }
    };
    
    // Class cha B
    class B: public A {
    public:
        void displayB() {
            std::cout << "This is class B" << std::endl;
        }
    };
    
    // Đa kế thừa
    class C : public A {
    public:
        void displayC() {
            std::cout << "This is class C" << std::endl;
        }
    };
    class D : public B,public C {
    public:
        void displayD() {
            std::cout << "This is class D" << std::endl;
        }
    };
    
    int main() {
        D obj;
        // obj.displayA(); // cái này không lỗi nhưng không biết gọi cái nào từ trong class nào cả
        obj.B::displayA(); // Gọi phương thức từ class A thông qua class B
        obj.B::displayB(); // Gọi phương thức của lớp B  thông uống lớp B
        obj.C ::displayA(); // Gọi phương thức của lớp A thông qua lớp C
        obj.C::displayC(); // Gọi phương thức của lớp B thông qua lớp C
        obj.D::displayB(); // Gọi phương thức của lớp B thông qua lớp D
        obj.D::displayC(); // Gọi phương thức của lớp C thông qua lớp D
        obj.displayD(); // Gọi phương thức của lớp D
        return 0;
    }