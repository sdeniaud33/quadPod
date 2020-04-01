#ifndef leg_h
#define leg_h
#include <servo.h>
#include <Arduino.h>

class Leg
{
private:
    Servo *_servoH;
    Servo *_servoV;

public:
    Leg(Servo *servoV, Servo *servoH);

    void init();
    void setAngleH(int angle);
    void setAngleV(int angle);
    void setPercentPosH(int percentPos);
    void setPercentPosV(int percentPos);
    void goToV(int pos);
    void goToH(int pos);
};
#endif
