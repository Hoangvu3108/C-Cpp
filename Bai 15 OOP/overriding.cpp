#include <iostream>
using namespace std;

class Animal {
public:
    void sound() {
        cout << "Some generic sound" << endl;
    }
};

class Dog : public Animal {
public:
    // Function overriding
    void sound() {
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog myDog;  
    myDog.sound(); 
    // Gọi method sound() của Dog, output: "Woof!"
}