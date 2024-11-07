//Libraries and Variables
#include <Servo.h>;

//Scene 1
int switchVal1;
const int switchPin1 = 10;
const int ledPin1 = 13;

//Scene 2
int switchVal2;
const int switchPin2 = 11;
const int ledPin2 = 4;

//Scene 3
Servo myservo; 
const int switchPin3 = 8;
const int switchPin4 = 9;

//Scene 4
int switchVal3;
const int switchPin5 = 12;
const int ledPin3 = 5;

//Scene 5
Servo myservo2;
const int switchPin6 = 7;

//Note for Future Reference: All inidividual parts should work code-wise

void setup() 
{

//Serial Printer
Serial.begin(9600);

//Scene 1
pinMode (switchPin1, INPUT);
pinMode (ledPin1, OUTPUT);

//Scene 2
pinMode (switchPin2, INPUT);
pinMode (ledPin2, OUTPUT);

//Scene 3 
myservo.attach(2);
pinMode(switchPin3, INPUT);
pinMode(switchPin4, INPUT);

//Scene 4
pinMode (switchPin5, INPUT);
pinMode (ledPin3, OUTPUT);

//Scene 5
myservo2.attach(2);
pinMode (switchPin6, INPUT);

}

void loop() 
{

//Scene 1: LEDs Light When Aurora Stands on Switch By Spindle
 switchVal1 = digitalRead(switchPin1);
  if (switchVal1 == HIGH)
  {
    digitalWrite(ledPin1, HIGH);
  }
  else
  {
    digitalWrite(ledPin1, LOW);
  }

//Scene 2: LEDs Light When Aurora Triggers Switch by the Bed
switchVal2 = digitalRead(switchPin2);
  if (switchVal2 == HIGH)
  {
    digitalWrite(ledPin2, HIGH);
  }
  else
  {
    digitalWrite(ledPin2, LOW);
  }

//Scene 3: Dragon Wings Moved by Servo Until Sword Inserted
if (digitalRead(switchPin3)==HIGH)
    {
      while (digitalRead(switchPin4)==LOW)
      {
        myservo.write(180);
        myservo.write(0);
      }
    
    }

//Scene 4: LEDs Light When Phillip Stands on Switch
 switchVal3 = digitalRead(switchPin5);
  if (switchVal3 == HIGH)
  {
    digitalWrite(ledPin3, HIGH);
  }
  else
  {
    digitalWrite(ledPin3, LOW);
  }

//Scene 5: Heart Swings Out When Phillip Stands on Switch
if (digitalRead(switchPin6)==HIGH)
    {
      myservo2.write(180);
    }

{
  
}

}
