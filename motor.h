#ifndef MOTOR_H
#define MOTOR_H

void writemotor(int m)          //take a duty value between -100 (full speed reverse) and 100 (full speed forward). set motor direction and duty cycle accordingly
{
  m = constrain(m, -100, 100);    //error proofing
  if(m>=0)
  {
    digitalWrite(in1pin, HIGH);     //forward on L298N
    digitalWrite(in2pin, LOW);
  }
  else
  {
    digitalWrite(in1pin, LOW);      //reverse on L298N
    digitalWrite(in2pin, HIGH);
  }
  m = abs(m);                       //convert range to 255 then analogwrite
  m = map(m, 0, 100, 0, 255);
  m = constrain(m, 0, 255);
  analogWrite(enapin, m);
}

void adjustmotor(int m)             //gradually bring motor towards its target speed instead of instantly changing it. Takes an input between -100 and 100% throttle
{
  m = constrain (m, -100, 100);
  
  if(((millis()-lastadj)<adjtime))  //see if enough time has passed since last adjustment
  {return;}
  else
  {lastadj = millis();}

  int a = da;
  dt = m;

  if(a>dt)
  {
    writemotor(a-adjval);       
    da = a-adjval;
  }
  else if(a<dt)
  {
    writemotor(a+adjval);
    da = a+adjval;
  }
  else
  {
    writemotor(a);
    da = a;
  }
  if(abs(a-dt)<=adjval)   //if its within the adjutment threshhold, write it directly to the target speed
  {
    writemotor(dt);
    da = dt;
  }
}


#endif