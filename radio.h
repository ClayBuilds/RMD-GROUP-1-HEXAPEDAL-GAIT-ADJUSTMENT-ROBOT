#ifndef RADIO_H
#define RADIO_H
//read the RC receiver and map it to useful ranges


void readthrot()  //reads radio signal for throttle channel, returns a value between -100 to 100 
{
  int raw = pulseIn(throtin, HIGH, 6000);
  if (raw != 0)
  {
    traw = raw;
    raw = raw+zerooffsett;
    traw = raw;
    raw = map(raw, throtinminpwm, throtinmaxpwm, -100 , 100);
    throtinval = constrain(raw, -100, 100);
    throtinval = throtinval*(-1);
  }

  
}

int readsteer() //reads radio signal for steering channel, returns a value between -100 to 100
{
  int raw = pulseIn(steerin, HIGH, 6000);
  if (raw != 0)
  {
    raw = raw + zerooffsets;
    sraw = raw;  
    raw = map(raw, steerinminpwm, steerinmaxpwm, ssoftlimlow , ssoftlimhigh);
    steerinval = constrain(raw, ssoftlimlow, ssoftlimhigh);
    steerinval = steerinval + angleoffset;
  }


}

#endif