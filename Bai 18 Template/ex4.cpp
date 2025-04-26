#include<iostream>

using namespace std;

template <typename T>

class Sensor {
    private:
        T value;

    public:
        Sensor(T init) : value(init) {}

        void readSensor(T newValue){
            value = newValue;
        }
        T getValue(){
            return value;
        }
        void displayValue(){
            cout << "Sensor value: " << value << endl;
        }
};

int main ()
{   // ở đây bắt buộc phải truyền vào kiểu dữ liệu của tham số đầu vào là int, double, string
    Sensor<int> intSensor(10);
    intSensor.displayValue(); // Output: Sensor value: 10

    Sensor<double> doubleSensor(3.14);
    doubleSensor.displayValue(); // Output: Sensor value: 3.14

    Sensor<string> stringSensor("OFF");
    stringSensor.displayValue(); // Output: Sensor value: Hello
    return 0;
}