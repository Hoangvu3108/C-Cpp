#include<stdio.h>

typedef struct{
    void (*startMotor)();
    void (*stopMotor)();
    void (*changeSpeed)(int gpio,int speed);
} motorcontroller;

 typedef int PIN;

 // CÁC HÀM CHUNG
 void startMotor(PIN pin){
        printf("Start motor at pin %d\n", pin);
}
void stopMotor(PIN pin){
        printf("Stop motor at pin %d\n", pin);
}
void changeSpeed(PIN pin, int speed){
        printf("Change speed of motor at pin %d to %d\n", pin, speed);
}
// Macro ddere khởi tạo GPIO VÀ MOTOR CONTROLLER
#define INIT_MOTOR_CONTROLLER(motorName, pinNumber)     \
   PIN Pin_##motorName = pinNumber;                      \
   motorcontroller motorName ={startMotor, stopMotor, changeSpeed};

int main(){
    // Sử dụng macro để khởi tạo motor controller
    INIT_MOTOR_CONTROLLER(motor1,12);
    INIT_MOTOR_CONTROLLER(motor2,13);

    motor1.startMotor(Pin_motor1);
    motor1.changeSpeed(Pin_motor1, 100);
    motor1.stopMotor(Pin_motor1);

    motor2.startMotor(Pin_motor2);
    motor2.changeSpeed(Pin_motor2, 200);
    motor2.stopMotor(Pin_motor2);
}