#include "leg.h"

Leg::Leg(Servo *servoV, Servo *servoH)
{
    this->_servoH = servoH;
    this->_servoV = servoV;
}

void Leg::init()
{
    this->_servoH->init();
    this->_servoV->init();
}

void Leg::setAngleH(int angle)
{
    this->_servoH->setAngle(angle);
}

void Leg::setAngleV(int angle)
{
    this->_servoV->setAngle(angle);
}

void Leg::setPercentPosH(int percentPos)
{
    this->_servoH->setPercentPosition(percentPos);
}

void Leg::setPercentPosV(int percentPos)
{
    this->_servoV->setPercentPosition(percentPos);
}

void Leg::goToH(int pos)
{
    this->_servoH->goTo(pos);
}

void Leg::goToV(int pos)
{
    this->_servoV->goTo(pos);
}

