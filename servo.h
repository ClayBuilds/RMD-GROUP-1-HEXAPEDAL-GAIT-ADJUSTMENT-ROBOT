#ifndef SERVO_H
#define SERVO_H

void sdeg(int d)    //take an input value in degrees, write the approppriate PWM signal to the servo
{
  d = constrain(d, smina, smaxa);
  sang = d;
  int p = map(d, smina, smaxa, sminp, smaxp);
  steer.writeMicroseconds(p);
  spwm = p;
}

#endif  