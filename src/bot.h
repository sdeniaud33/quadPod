#ifndef bot_h
#define bot_h
#include <leg.h>
#include <Arduino.h>
#include <oscillator.h>

class Bot
{

public:
    static const byte FRONT_LEFT = 0;
    static const byte REAR_LEFT = 1;
    static const byte REAR_RIGHT = 2;
    static const byte FRONT_RIGHT = 3;

    Bot(Leg *legFL, Leg *legRL, Leg *legRR, Leg *legFR);
    void execute(float period[8], int amplitude[8], int offset[8], int phase[8]);

    void turnL();
    void init();
    void idle();
    void walk();
    void dance();
    void loop();
    void pushUp();
    void upDown();
    void moonwalkL();
    Leg *legs[4];

private:
    Oscillator oscillator[8];
};
#endif
