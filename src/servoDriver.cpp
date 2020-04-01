#include "ServoDriver.h"

ServoDriver::ServoDriver()
{
}

void ServoDriver::init()
{
    _driver.begin();
    // In theory the internal oscillator is 25MHz but it really isn't
    // that precise. You can 'calibrate' by tweaking this number till
    // you get the frequency you're expecting!
    _driver.setOscillatorFrequency(27000000); // The int.osc. is closer to 27MHz
    _driver.setPWMFreq(50);                   // Analog servos run at ~50 Hz updates

    delay(10);
}

void ServoDriver::setPWM(int servoNum, int pulseLen)
{
    _driver.setPWM(servoNum, 0, pulseLen);
}

void ServoDriver::setAngle(int servoNum, int degrees)
{
    int pulseLen = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
    // Serial.print(degrees);
    // Serial.print(" -> ");
    // Serial.print(pulseLen);
    // Serial.println();
    this->setPWM(servoNum, pulseLen);
}
