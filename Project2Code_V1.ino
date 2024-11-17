//Libraries and Variables
#include <Servo.h>;

//Scene 1
int switchVal1;
const int switchPin1 = 11;
const int ledPin1 = 13;

//Scene 2
int switchVal2;
const int switchPin2 = 10;
const int ledPin2 = 6;

//Scene 3
Servo myservo;
Servo myservo2; 
int switchVal4State;
int switchVal5State;
int lastSwitchVal4State;
int lastSwitchVal5State;
bool(isRunning) = false; //tracks if Dragon servos are active
bool(isMoving) = false;
const int switchPin3 = 8;
const int switchPin4 = 9;

//Scene 4
int switchVal3;
const int switchPin5 = 7;
const int ledPin3 = 5;

//Scene 5
Servo myservo3;
int switchVal6;
const int switchPin6 = 12;

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
myservo.attach(3);
myservo2.attach(4);
pinMode(switchPin3, INPUT);
pinMode(switchPin4, INPUT);


//Scene 4
pinMode (switchPin5, INPUT);
pinMode (ledPin3, OUTPUT);

//Scene 5
myservo3.attach(2);
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
switchVal4State = digitalRead(switchPin3);
Serial.println(switchVal4State);
switchVal5State = digitalRead(switchPin4);


  // Handle button A (start movement)
  if (switchVal4State != lastSwitchVal4State) {
    isRunning = false; // Start movement
    isMoving = true;
    Serial.println("Wings are moving");
    lastSwitchVal4State = switchVal4State;
  }

  // Handle button B (stop movement)
  if (switchVal5State != lastSwitchVal5State) {
    isRunning = false; // Stop movement
    isMoving = false;
    Serial.println("Dragon is dead");
    lastSwitchVal5State = switchVal5State;
  }

  // If moving, cycle servos between 0 and 90 degrees
  if (isMoving) {
    Serial.println(isMoving);
    for (int pos = 0; pos <= 90; pos++) {
      myservo.write(pos);
      myservo2.write(pos);
      delay(5); // Adjust speed of movement
    }
    for (int pos = 90; pos >= 0; pos--) {
      myservo.write(pos);
      myservo2.write(pos);
      delay(5); // Adjust speed of movement
    }
  }


//Scene 4: LEDs Light When Phillip Stands on Switch
   if (digitalRead(switchPin5) == HIGH)
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
      myservo3.write(180);
    }

{
  
}
  

}
