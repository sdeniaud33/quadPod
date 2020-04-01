#include "bot.h"

Bot::Bot(Leg *legFL, Leg *legRL, Leg *legRR, Leg *legFR)
{
    this->legs[FRONT_LEFT] = legFL;
    this->legs[REAR_LEFT] = legRL;
    this->legs[REAR_RIGHT] = legRR;
    this->legs[FRONT_RIGHT] = legFR;
}

void Bot::init()
{
    for (int i = 0; i < 4; i++)
    {
        this->legs[i]->init();
    }
}

void Bot::idle()
{
    for (int i = 0; i < 4; i++)
    {
        this->legs[i]->setAngleH(90);
        this->legs[i]->setAngleV(30);
    }
}

void Bot::walk()
{
    for (int i = 0; i < 4; i++)
    {
        this->legs[i]->setAngleH(30);
        this->legs[i]->setAngleV(30);
    }
    for (int i = 0; i < 30; i++)
    {
        this->legs[this->FRONT_LEFT]->setAngleV(30 - i);
    }
}

void Bot::turnL()
{

    float T = 1000;
    int x_amp = 15;
    int z_amp = 25;
    int ap = 15;
    int hi = 0;
    float period[] = {T, T, T, T, T, T, T, T};
    int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
    int offset[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
    int phase[] = {180, 0, 90, 90, 0, 180, 90, 90};

    execute(period, amplitude, offset, phase);
}

void Bot::pushUp()
{
    /*
   (servo index, pin to attach pwm)
   __________ __________ _________________
  |(3,9)_____)(1,8)      (0,2)(______(2,3)|
  |__|       |left FRONT right|        |__|
             |                |
             |                |
             |                |
   _________ |                | __________
  |(7,7)_____)(5,6)______(4,4)(______(6,5)|
  |__|                                 |__|
*/

    float T = 2000;
    int z_amp = 40;
    int x_amp = 65;
    int hi = 0;
    float period[] = {T, T, T, T, T, T, T, T};
    int amplitude[] = {0, 0, z_amp, z_amp, 0, 0, 0, 0};
    int offset[] = {90, 90, 90 - hi, 90 + hi, 90 - x_amp, 90 + x_amp, 90 + hi, 90 - hi};
    int phase[] = {0, 0, 0, 180, 0, 0, 0, 180};

    execute(period, amplitude, offset, phase);
}


void Bot::upDown() {
    float T = 3000;
  int x_amp = 0;
  int z_amp = 35;
  int ap = 20;
  //int hi = 25;
  int hi = 0;
  int front_x = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {    90 + ap - front_x,
                      90 - ap + front_x,
                      90 - hi,
                      90 + hi,
                      90 - ap - front_x,
                      90 + ap + front_x,
                      90 + hi,
                      90 - hi
                 };
  int phase[] = {0, 0, 90, 270, 180, 180, 270, 90};

  execute(period, amplitude, offset, phase);
}

void Bot::moonwalkL() {
    float T=2000;
  int z_amp = 45;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 0, z_amp, z_amp, 0, 0, z_amp, z_amp};
  int offset[] = {90, 90, 90, 90, 90, 90, 90, 90};
  int phase[] = {0, 0, 0, 120, 0, 0, 180, 290};

  execute(period, amplitude, offset, phase);
}

void Bot::loop()
{
    /*
   (servo index, pin to attach pwm)
   __________ __________ _________________
  |(3,9)_____)(1,8)      (0,2)(______(2,3)|
  |__|       |left FRONT right|        |__|
             |                |
             |                |
             |                |
   _________ |                | __________
  |(7,7)_____)(5,6)______(4,4)(______(6,5)|
  |__|                                 |__|
*/

    if (!oscillator[1].isStop())
        this->legs[this->FRONT_LEFT]->setAngleH(this->oscillator[1].refresh());
    if (!oscillator[3].isStop())
        this->legs[this->FRONT_LEFT]->setAngleV(this->oscillator[3].refresh());
    if (!oscillator[0].isStop())
        this->legs[this->FRONT_RIGHT]->setAngleH(this->oscillator[0].refresh());
    if (!oscillator[2].isStop())
        this->legs[this->FRONT_RIGHT]->setAngleV(this->oscillator[2].refresh());
    if (!oscillator[5].isStop())
        this->legs[this->REAR_LEFT]->setAngleH(this->oscillator[5].refresh());
    if (!oscillator[7].isStop())
        this->legs[this->REAR_LEFT]->setAngleV(this->oscillator[7].refresh());
    if (!oscillator[4].isStop())
        this->legs[this->REAR_RIGHT]->setAngleH(this->oscillator[4].refresh());
    if (!oscillator[6].isStop())
        this->legs[this->REAR_RIGHT]->setAngleV(this->oscillator[6].refresh());
    // for (int i = 0; i < 8; i += 2)
    // {
    //     if (!oscillator[i].isStop())
    //     {
    //         this->legs[i / 2]->setAngleH(this->oscillator[i].refresh());
    //         if (!oscillator[i + 1].isStop())
    //         {
    //             this->legs[i / 2]->setAngleV(this->oscillator[i + 1].refresh());
    //         }
    //     }
    // }
}

void Bot::execute(float period[8], int amplitude[8], int offset[8], int phase[8])
{
    for (int i = 0; i < 8; i++)
    {
        oscillator[i].setPeriod(period[i]);
        oscillator[i].setAmplitude(amplitude[i]);
        oscillator[i].setPhase(phase[i]);
        oscillator[i].setOffset(offset[i]);
        oscillator[i].start();
        oscillator[i].setTime(millis());
    }
}

void Bot::dance()
{
    int len = 20;

    Serial.println("Walk");
    for (int i = 0; i < 4; i++)
    {
        this->legs[i]->setAngleH(0);
    }
    for (int i = 0; i < 4; i++)
    {
        this->legs[i]->setAngleV(len);
    }
    int speed = 50;
    Serial.println("Step 1");
    // STEP 1
    for (int d = -len; d < len; d++)
    {
        this->legs[this->FRONT_LEFT]->setAngleV(len - d);
        this->legs[this->FRONT_RIGHT]->setAngleV(len - d);
        this->legs[this->REAR_LEFT]->setAngleV(len + d);
        this->legs[this->REAR_RIGHT]->setAngleV(len + d);
        delay(speed);
    }
    for (int d = len; d > -len; d--)
    {
        this->legs[this->FRONT_LEFT]->setAngleV(len - d);
        this->legs[this->FRONT_RIGHT]->setAngleV(len - d);
        this->legs[this->REAR_LEFT]->setAngleV(len + d);
        this->legs[this->REAR_RIGHT]->setAngleV(len + d);
        delay(speed);
    }
}
