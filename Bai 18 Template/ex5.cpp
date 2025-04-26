#include<iostream>

using namespace std;
class Temperature{
    private: 
        double temperature;
    public: // Gioi hạn phạm vi khi có const thì không cần phải khai báo lại biến trong hàm
        double getValue()const{
            return 40.5;
        }
        string getUnit()const{
            return "Celsius";
        }

};
class TirePressure{
    public:
        int getValue()const{
            return 32;
        }
        string getUnit()const{
            return "PSI";
        }
    private:
};
template <typename Sensor1, typename Sensor2>
class VehicleSensor{
    private:
        Sensor1 sensor1;
        Sensor2 sensor2;
    public:
        VehicleSensor(Sensor1 s1, Sensor2 s2): sensor1(s1), sensor2(s2){}
        void displaySensorData(){
            cout << "Sensor 1: " << sensor1.getValue() << " " << sensor1.getUnit() << endl;
            cout << "Sensor 2: " << sensor2.getValue() << " " << sensor2.getUnit() << endl;
        }  
};
int main(){
    Temperature tempSensor;
    TirePressure tireSensor;
    VehicleSensor<Temperature, TirePressure> vehicleSensor(tempSensor, tireSensor);
    vehicleSensor.displaySensorData();
    return 0;
}