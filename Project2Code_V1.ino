//Comment from Syd for assignment
//Comment from Jasmine for assignment
//Libraries and Variables
#include <Servo.h>;

//LEDs and Associated Switches
int LEDswitchVal1;
const int LEDswitchPin1 = 10; //temp pin number
const int ledPin1 = 4; //temp pin number

//Servos and Associated Switches 
Servo myservo1;
const int servoSwitchPin1 = 3; //temp pin number 



//code LEds to light up at spindle via switch, LEDs to light up at bed via switch
//code dragon wings to move via switch and keep moving until another switch is activated
//code more lEDs to light after dragon via switch 
//code servo to swing out heart via switch



void setup() 
{

//Serial Printer
Serial.begin(9600);

//LEDs and Associated Switches
pinMode (LEDswitchPin1, INPUT);

//Servos and Associated Switches 
myservo1.attach(9); //temp pin number
pinMode(servoSwitchPin1, INPUT);


}

void loop() 
{

//Scene 1: LEDs Light When Aurora Stands on Switch By Spindle
LEDswitchVal1 = digitalRead(LEDswitchPin1);
if (LEDswitchVal1 = HIGH)
{
  digitalWrite(ledPin1, HIGH);
}
else
{
  digitalWrite(ledPin1, LOW);
}

//Scene 2: LEDs Light When Aurora Triggers Switch by the Bed

{
  
}
  

}
