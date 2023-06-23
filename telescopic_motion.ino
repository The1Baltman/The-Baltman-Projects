#include <Servo.h>

// Stepper

const int stepPin = 2;
const int dirPin = 3;

// Servo

Servo servo;

// Potentiometer

const int pot = A1;

// Stepper buttons

const int left_b = 6;
const int right_b = 7;

int val;

int buttonstateone = 0;
int buttonstatetwo = 0;

void setup() {

// Stepper

    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);

// Servo

    servo.attach(5);
    servo.write(0);
    delay(1000);

// Buttons

    pinMode(left_b, INPUT_PULLUP);
    pinMode(right_b, INPUT_PULLUP);

// Serial

    pinMode(pot, INPUT);

    Serial.begin(9600);
    
}

void loop() {

      val = analogRead(1);
      int pot = map(val, 0, 1023, 0, 180);

      Serial.println("Potenciometer value");
      Serial.println(" ");
      Serial.println(pot);
      delay(599);
      
      buttonstateone = digitalRead(left_b);
      buttonstatetwo = digitalRead(right_b);

       Serial.println(buttonstateone);
       Serial.println(buttonstatetwo);

        servo.write(pot);

          if(buttonstateone == LOW)
    {
          digitalWrite(dirPin, HIGH);
    
          digitalWrite(stepPin,HIGH);
          
          delayMicroseconds(500);
          
          digitalWrite(stepPin,LOW);
          
          delayMicroseconds(500);
    }
    if(buttonstatetwo == LOW)
    {
          digitalWrite(dirPin, LOW);

          digitalWrite(stepPin,HIGH);
          
          delayMicroseconds(500);
          
          digitalWrite(stepPin,LOW);
          
          delayMicroseconds(500);

    }

}
