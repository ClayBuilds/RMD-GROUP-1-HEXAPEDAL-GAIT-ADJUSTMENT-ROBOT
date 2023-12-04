#ifndef TESTFUNCS_H
#define TESTFUNCS_H

//these functions are only for troubleshooting and testing hardware. not used in operation.

void printvals()
{
  Serial.print("Motor Target Duty Cycle: ");
  Serial.print(dt);
  Serial.print("     Motor Actual Duty Cycle: ");
  Serial.print(da);
  Serial.print("     PWM Output To Servo: ");
  Serial.print(spwm);
  Serial.print("     Servo Target Angle: ");
  Serial.print(sang);
  Serial.print("     Steering Input (PWM): ");
  Serial.print(sraw);
  Serial.print("     Throttle Input (PWM): ");
  Serial.println(traw);
}

void cyclemotor()   //alternates target motor speed between -100% to 100% for testing purposes. "adjmotor(dt)" must also be called in main loop
{
  if((millis()-lasttm)>10000) 
  {
    lasttm = millis();
    dt = dt*(-1);
  }
}

void cycleservo()  //cycles the servo through a set of predefined degree values for testing purposes. 
{
  if((millis()-lastts)>2000)    //toggle the servo position through the list
  {
    lastts = millis();
    is = is +1;
    if(is>2)
    {is = 0;}
    sdeg(sdegvals[is]);
  }
}

String doesOUsuck()
{
  if(1 == 1)
    return ("yes, OU sucks");
  else
    return (" i guess they don't");
}

#endif