#ifndef Servo_h
#define Servo_h
#include <servo.h>
#include <servoDriver.h>
#include <Arduino.h>

class Servo
{
private:
    byte _servoNum;
    int _min;
    int _max;
    int _angle;
    bool _isReverse;
    ServoDriver _driver;

public:
    Servo(ServoDriver driver, byte servoNum, int min, int max);

    void init();
    void goTo(int pos);
    void setAngle(int pos);
    void setPercentPosition(int percentPos);
    int getPosition();
};
#endif
