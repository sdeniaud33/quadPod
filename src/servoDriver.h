#ifndef ServoDriver_h
#define ServoDriver_h
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>

class ServoDriver
{
#define SERVOMIN 50 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600 // This is the 'maximum' pulse length count (out of 4096)

private:
    Adafruit_PWMServoDriver _driver = Adafruit_PWMServoDriver();

public:
    void init();
    void setPWM(int servoNum, int pulseLen);
    void setAngle(int servoNum, int degrees);
    ServoDriver();
};
#endif
