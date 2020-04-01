#include <Arduino.h>
#include <servo.h>
#include <servoDriver.h>
#include <leg.h>
#include <bot.h>

ServoDriver driver = ServoDriver();
Bot bot(
	/* 0 - FRONT LEFT  */ new Leg(new Servo(driver, 0, 100, 20), new Servo(driver, 4, 30, 130)),
	/* 1 - REAR LEFT   */ new Leg(new Servo(driver, 1, 120, 35), new Servo(driver, 5, 20, 135)),
	/* 2 - REAR RIGHT  */ new Leg(new Servo(driver, 2, 50, 140), new Servo(driver, 6, 20, 130)),
	/* 3 - FRONT RIGHT */ new Leg(new Servo(driver, 3, 130, 45), new Servo(driver, 7, 135, 30)));

void setup()
{
	driver.init();
	Serial.begin(9600);
	Serial.println("Start");
	bot.init();
	// bot.idle();
	// bot.pushUp();
	bot.moonwalkL();
	// bot.turnL();
	// bot.upDown();
	// for (int i = 0; i < 4; i++)
	// {
	// 	bot.legs[i]->setAngleV(0);
	// }
	// delay(2000);
	// for (int i = 0; i < 4; i++)
	// {
	// 	bot.legs[i]->setAngleV(180);
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	bot.legs[i]->setAngleH(135);
	// }

	// int legId = bot.REAR_LEFT;
	// bot.legs[legId]->setAngleH(0); // 0
	// delay(5000);
	// bot.legs[legId]->setAngleH(180); // 0
	// for (int i = 0; i < 180; i++)
	// {
	// 	bot.legs[bot.FRONT_LEFT]->setAngleH(i);		 // 0
	// 	bot.legs[bot.FRONT_RIGHT]->setAngleH(i); // 3
	// 	delay(5);
	// }
}

int idx = 100;
void loop()
{
	bot.loop();
	/*	
	for (int d = 0; d < 100; d++)
	{
		delay(10);
		for (int i = 0; i < 4; i++)
		{
			bot.legs[i]->setPosH(d);
			bot.legs[i]->setPosV(d);
		}
	}
	for (int d = 100; d > 0; d--)
	{
		delay(10);
		for (int i = 0; i < 4; i++)
		{
			bot.legs[i]->setPosH(d);
			bot.legs[i]->setPosV(d);
		}
	}
*/
}