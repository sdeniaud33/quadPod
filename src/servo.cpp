#include "servo.h"
#include "servoDriver.h"

Servo::Servo(ServoDriver driver, byte servoNum, int min, int max)
{
    this->_driver = driver;
    this->_servoNum = servoNum;
    if (min <= max)
    {
        this->_isReverse = false;
        this->_min = min;
        this->_max = max;
    }
    else
    {
        this->_isReverse = true;
        this->_min = min;
        this->_max = max;
    }
}

void Servo::init()
{
}

void Servo::setAngle(int angle)
{
    int val = map(angle, 0, 180, this->_min, this->_max);
    this->_angle = val;
    this->_driver.setAngle(this->_servoNum, val);
}

void Servo::setPercentPosition(int percentPos)
{
    int val = map(percentPos, 0, 100, this->_min, this->_max);
    this->_angle = val;
    this->_driver.setAngle(this->_servoNum, val);
}

void Servo::goTo(int pos)
{
    /*
    int step;
    int from;
    int to;
    if (this->_angle <= pos)
    {
        step = 1;
        from = this->_angle;
        to = pos;
    }
    else
    {
        step = -1;
        from = this->_angle;
        to = pos;
    }
    for (int p = from; step == 1 ? p < to : p > to; p += step)
    {
        this->setPosition(p);
        delay(100);
    }
    */
}

int Servo::getPosition()
{
    return this->_angle;
}
