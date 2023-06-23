#include <LiquidCrystal.h>

int button = 2;
const int dirPin = 3;

const int stepPinone = 4;
const int dirPinone = 5;

const int pot = A0;

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal screen(rs, en, d4, d5, d6, d7);

void setup() {

pinMode(pot, INPUT);
pinMode(button, INPUT);

Serial.begin(9600);

screen.begin(16, 2);
screen.clear();
screen.setCursor(0, 0);
screen.print("     A.U.T.");
screen.setCursor(0, 1);
screen.print("TELESCOPE MOTION");
delay(5000);
screen.clear();
delay(2000);
screen.setCursor(0, 0);
screen.print("BY");
screen.setCursor(0, 1);
screen.print("NEVARKS ROBOTICS");
delay(5000);
screen.clear();
delay(2000);
screen.setCursor(0, 0);
screen.print("INITIALIZING...");
delay(5000);
screen.clear();
delay(2000);
screen.setCursor(0, 0);
screen.print("STATUS:");
}

void loop() {

screen.setCursor(0, 1);

int buttonvalue = digitalRead(button);

Serial.println(buttonvalue);

int x = 0;

if (buttonvalue == LOW)
{
   x = x++;
   delay(100);
   
screen.print(x);
}

else if (x = 5)
{
  x = 0;
}


}
