#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for age
    void setAge(int newAge) {
        if (newAge > 0) { // Ensure age is positive
            age = newAge;
        } else {
            std::cout << "Age must be positive!" << std::endl;
        }
    }

    // Getter for age
    int getAge() const {
        return age;
    }
};

int main() {
    Person person;

    // Set values using setters
    person.setName("John Doe");
    person.setAge(25);

    // Get values using getters
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;

    return 0;
}