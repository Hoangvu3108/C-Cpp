#include <iostream>
using namespace std;

// Class cha
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
    // public method, truy cập private gián tiếp!
    void accessPrivate() {
        breathe();
    }

protected:
    void sleep() {
        cout << "Animal is sleeping" << endl;
    }

private:
    void breathe() {
        cout << "Animal is breathing" << endl;
    }
};

// Class con
class Dog : public Animal {
public:
    void accessProtected() {
        // sleep() truy cập thoải mái ở trong class con.
        sleep();  
    }
};

int main() {
    Dog myDog;
    // eat() ở class cha là public ở class con là public, eat() truy cập ở đâu cũng được.
    myDog.eat(); 
    // sleep() ở class cha là protected ở class con là protected, sleep() truy cập qua phương thức public của class con.
    myDog.accessProtected();
    // breathe() ở class cha là private, chỉ truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
    myDog.accessPrivate();    
}