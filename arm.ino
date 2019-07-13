#include <Servo.h>

int thumb = 3;            //Output pin for Thumb
int index = 5;            //Output pin for Index Finger
int middle = 6;           //Output pin for Middle Finger
int ring = 9;             //Output pin for Ring Finger
int pinky = 10;           //Output pin for Pinky Finger

int thumbSense = A0;      //Input pin for Thumb Force Sensor
int indexSense = A1;      //Input pin for Index Force Sensor
int middleSense = A2;     //Input pin for Middle Force Sensor
int ringSense = A3;       //Input pin for Ring Force Sensor
int pinkySense = A4;      //Input pin for Pinky Force Sensor

int flexMax = 700;        // Max value of Flex received
int flexMin = 400;        // Min value of Flex received

Servo servothumb;         // Define Thumb Servo
Servo servoindex;         // Define Index Finger Servo
Servo servomiddle;        // Define Middle Finger Servo
Servo servoring;          // Define Ring Finger Servo
Servo servopinky;         // Define Pinky (Little) Finger Servo

void setup()              // Define Pins and Objects
{ 
  Serial.begin(9600);     // Begin Serial interface with baudrate 9600
  
  pinMode(thumb, OUTPUT);       //Define Thumb pin as Output pin
  pinMode(index, OUTPUT);       //Define Index pin as Output pin
  pinMode(middle, OUTPUT);      //Define Middle pin as Output pin
  pinMode(ring, OUTPUT);        //Define Ring pin as Output pin
  pinMode(pinky, OUTPUT);       //Define Pinky pin as Output pin
  
  pinMode(thumbSense, INPUT);       //Define Thumb Sensor pin as Input pin
  pinMode(indexSense, INPUT);       //Define Index Sensor pin as Input pin
  pinMode(middleSense, INPUT);      //Define Middle Sensor pin as Input pin
  pinMode(ringSense, INPUT);        //Define Ring Sensor pin as Input pin
  pinMode(pinkySense, INPUT);       //Define Pinky Sensor pin as Input pin
  
  delay(50);                    //Delay of 50 Microseconds
  
  servothumb.attach(thumb);       //Set Thumb pin to Servo Object  
  servoindex.attach(index);       //Set Index pin to Servo Object
  servomiddle.attach(middle);     //Set Middle pin to Servo Object
  servoring.attach(ring);         //Set Ring pin to Servo Object
  servopinky.attach(pinky);       //Set Pinky pin to Servo Object

  delay(50);                    //Delay of 50 Microseconds
  
} 

void loop() 
{
    while( Serial.available() == 0); //If No data is received, No actions will be performed
    
    if(Serial.peek() == 'T')  //Flex Value for Thumb Recieved
    {
      int angle = Serial.parseInt();
      servothumb.write(angle);  
      Serial.println('T');
    }
    if(Serial.peek() == 'I')  //Flex Value for Index finger Recieved
    {
      int angle = Serial.parseInt();
      servoindex.write(angle);  
      Serial.println('I');
    }
    if(Serial.peek() == 'M')  //Flex Value for Middle Finger Recieved
    {
      int angle = Serial.parseInt();
      servomiddle.write(angle);  
      Serial.println('M');
    }
    if(Serial.peek() == 'R')  //Flex Value for Ring Finger Recieved
    {
      int angle = Serial.parseInt();
      servoring.write(angle);  
      Serial.println('R');
    }
    if(Serial.peek() == 'P')  //Flex Value for Pinky Finger Recieved
    {
      int angle = Serial.parseInt();
      servopinky.write(angle);  
      Serial.println('P');
    }
     
 while (Serial.available() > 0)  //Keep Reading Serial Data
    {
      Serial.read();
      
    }
    delay(15);        //Delay of 15 Microseconds
}

