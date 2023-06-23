
//Libraries

  #include <LiquidCrystal.h>
  #include <Servo.h>
  
//Libraries

const int led_one = 10;
const int led_two = 11;


// Buttons

const int fast_button_x_pos = 22;
const int fast_button_x_neg = 23;


const int andromeda_button = 30;


const int sirius_button = 31;


const int casiopea_button = 32;


const int mode_button = 34;


  //Read Buttons

int read_fast_button_x_pos = 0;
int read_fast_button_x_neg = 0;
int read_andromeda_button = 0;
int read_sirius_button = 0;
int read_casiopea_button = 0;

    //Mode counter
    
int read_mode_button = 0;
int count_value = 0;
int pre_estate = 0;
    //Mode counter
    
  //Read Buttons

// Buttons

// Steppers

const int stepper_x_dir = 49;
const int stepper_x_step = 48;

// Steppers

// Servo

Servo servo;

const int potenciometer = A7;
int val;

// Servo

// LCD

  const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal screen(rs, en, d4, d5, d6, d7);

// LCD


void setup() {


  pinMode(led_one, OUTPUT);
  pinMode(led_two, OUTPUT);

// Buttons

  pinMode(fast_button_x_pos, INPUT_PULLUP);
  pinMode(fast_button_x_neg, INPUT_PULLUP);

  pinMode(andromeda_button, INPUT_PULLUP);
  pinMode(sirius_button, INPUT_PULLUP);
  pinMode(casiopea_button, INPUT_PULLUP);

  pinMode(mode_button, INPUT);

// Buttons

// Steppers

  pinMode(stepper_x_dir, OUTPUT);
  pinMode(stepper_x_step, OUTPUT);

// Servo

  pinMode(potenciometer, INPUT);
  servo.attach(26);
  servo.write(0);


// Servo

// Steppers

// LCD

  screen.begin(16, 2);
  screen.clear();
  screen.setCursor(0, 0);
  screen.print("A.U.T.");
  screen.setCursor(0, 1);
  screen.print("ALPHA PROTOTYPE");
  delay(2000);
  screen.clear();
  screen.setCursor(0, 0);
  screen.print("BY");
  screen.setCursor(0, 1);
  screen.print("BA.KE.OS. ROBOTS");
  delay(2000);
  screen.clear();
  screen.setCursor(0, 0);
  screen.print("    WELCOME");
  delay(1000);
  screen.clear();
// LCD

//Serial

Serial.begin(9600);

//Serial

}





void loop() {


    read_mode_button = digitalRead(mode_button);

    if(read_mode_button == HIGH and count_value == 0 and pre_estate == 0)
    {
      count_value = 1;
      pre_estate = 1;
    }
   
    else if(read_mode_button == HIGH and count_value == 1 and pre_estate == 0)
    {
      count_value = 0;
      pre_estate = 1;

    } 
    if(read_mode_button == LOW)
    {
      pre_estate = 0;
    }
   Serial.println(count_value);

      delay(20);

    switch(count_value){
      case 0:
              read_fast_button_x_pos = digitalRead(fast_button_x_pos);
        read_fast_button_x_neg = digitalRead(fast_button_x_neg);
      digitalWrite(led_one, LOW);
      digitalWrite(led_two, HIGH);

      screen.clear();
      screen.setCursor(0, 0);
      screen.print("CURRENTLY AT:");


        val = analogRead(potenciometer);
        val = map(val, 0, 1023, 0, 180);
    
        servo.write(val);

      screen.setCursor(0, 1);
      screen.print(val);
            screen.setCursor(4, 1);
      screen.print("DEGREES");
          //Fast X

        if(read_fast_button_x_pos == LOW)
        {
          digitalWrite(stepper_x_dir, HIGH);

          digitalWrite(stepper_x_step, HIGH);
          delayMicroseconds(600);
          digitalWrite(stepper_x_step, LOW);
          delayMicroseconds(600);
        }
    
        if(read_fast_button_x_neg == LOW)
        {
          digitalWrite(stepper_x_dir, LOW);

          digitalWrite(stepper_x_step, HIGH);
          delayMicroseconds(600);
          digitalWrite(stepper_x_step, LOW);
          delayMicroseconds(600);
        }
   
            //Fast X
          break;
            
        case 1:
       digitalWrite(led_one, HIGH);
       digitalWrite(led_two, LOW);
              screen.clear();
      screen.setCursor(0, 0);
      screen.print("CURRENTLY AT:");
      screen.setCursor(0, 1);
      screen.print("AUTONOMOUS MODE");
              read_andromeda_button = digitalRead(andromeda_button);
              read_sirius_button = digitalRead(sirius_button);
              read_casiopea_button = digitalRead(casiopea_button);

                //Automatic movement

    if(read_andromeda_button == LOW)
    {
      screen.clear();
      screen.setCursor(0, 0);
      screen.print("NOW POINTING AT:");
      screen.setCursor(0, 1);
      screen.print("ANDROMEDA");
      delay(2000);
      digitalWrite(stepper_x_dir, LOW);

      for(int x = 0; x < 50; x++)
      {
      
      digitalWrite(stepper_x_step, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepper_x_step, LOW);
      delayMicroseconds(3000);
      }
      delay(1000);

      servo.write(0);
      delay(500);
      servo.write(70);
              delay(2000);

    }

        if(read_sirius_button == LOW)
    {
      screen.clear();
      screen.setCursor(0, 0);
      screen.print("NOW POINTING AT:");
      screen.setCursor(0, 1);
      screen.print("SIRIUS");
            delay(2000);

      digitalWrite(stepper_x_dir, HIGH);

      for(int x = 0; x < 90; x++)
      {
      
      digitalWrite(stepper_x_step, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepper_x_step, LOW);
      delayMicroseconds(3000);
      }
      delay(1000);

      servo.write(0);
      delay(500);
      servo.write(170);
            delay(2000);

    }

        if(read_casiopea_button == LOW)
    {
      screen.clear();
      screen.setCursor(0, 0);
      screen.print("NOW POINTING AT:");
      screen.setCursor(0, 1);
      screen.print("CASIOPEA");
            delay(2000);

      digitalWrite(stepper_x_dir, LOW);

      for(int x = 0; x < 87; x++)
      {
      
      digitalWrite(stepper_x_step, HIGH);
      delayMicroseconds(3000);
      digitalWrite(stepper_x_step, LOW);
      delayMicroseconds(3000);
      }
      delay(1000);

      servo.write(0);
      delay(500);
      servo.write(130);
      delay(2000);
    }
      break;
  //Automatic movement

      default:
      servo.write(0);
      break;
    }

}
