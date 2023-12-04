//Clay McPherson
// 11-27-23
//Final Project RMD VERSION 7



#include <Servo.h>

#include "pinout.h"
#include "MiscVariables.h"
#include "servo.h"
#include "motor.h"
#include "testfuncs.h"
#include "radio.h"

byte testmode = 0; //set to 1 for test mode (sets motor speed and servo position according to manually specified values below), 0 for normal mode (does nothing without transmiter/receiver plugged in, otherwise follows its input)
int testthrot = 50;
int teststeer = 0;

void setup() 
{
  Serial.begin(9600);
  steer.attach(servopin);
  pinMode(enapin, OUTPUT);
  pinMode(in1pin, OUTPUT);
  pinMode(in2pin, OUTPUT);
  pinMode(steerin, INPUT);
  pinMode(throtin, INPUT);
  analogWrite(enapin, 0);
  digitalWrite(in1pin, LOW);
  digitalWrite(in2pin, LOW);
  startt = millis();
}

void loop() 
{
  readthrot();  //read Radio signal for throttle
  readsteer();  //read radio signal for steering 
  
  if(testmode)  //check if test mode is active
  {
    //cyclemotor();  test functions that run actuators through a range
    //cycleservo();
    
    dt = testthrot;
    sdeg(teststeer);
  }
  else
  {
    dt = throtinval;    //set drive motor target to value taken from receiver
    sdeg(steerinval);   //set servo to the appropriate angle
  }

  
  adjustmotor(dt);      //ramp motor up or down towards its target value
  printvals();          //print realtime parameters over serial for debugging
}
