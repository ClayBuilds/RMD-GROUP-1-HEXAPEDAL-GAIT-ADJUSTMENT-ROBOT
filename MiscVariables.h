//miscellaneous variables


#ifndef MISCVARIABLES_H
#define MISCVARIABLES_H

Servo steer;  //steering servo
int sdegvals[] = {-90, 0, 90};  //set values for servo to go to during test cycle. not used for driving.
int spwm = 0;   //servo pwm (µs)
int sang = 0;   //servo angle (degrees)
int da = 0;     //drive motor actual duty cycle (%)
int dt = 100;   //drive motor target duty cycle (%)
int dpwmt = 0;  //drive motor target pwm (µs)
int dpwma = 0;  //drive motor actual pwm (µs)
int spwma = 1500;   //servo actual pwm (µs) 
int sdega = 0;      //servo actual degrees 
int sminp = 500;    //minimum PWM signal to position the servo fully at its lower mechanical limit
int smaxp = 2500;   //maximum PWM signal to position the servo fully at its upper mechanical limit
int smina = -90;    //minimum travel angle of servo at mechanical limit
int smaxa = 90;     //maximum travel angle of servo at mechanical limit
int ssoftlimlow = -30;    //soft servo lower limit (degrees), software will not allow it to exceed this
int ssoftlimhigh = 30;    //soft servo upper limit (degrees), software will not allow it to exceed this
int angleoffset = -9;     //servo trim (degrees) so that steering is straight with no RC input
byte is = 0;              //indexes for test mode servo values
unsigned long startt = 0;   //start time (milliseconds)
unsigned long tm = 0;       //drive motor time (used for regulating adjustment speed)
unsigned long lasttm = 0;   //last motor adjustment time (used test cycle only)
unsigned long ts = 0;       //servo time (used for test cycle only)
unsigned long lastts = 0;   //last servo time (used for test cycle only)
unsigned long lastadj = 0;  //last motor adjustment time
unsigned long adjtime = 5;  //time between adjustments (miliseconds)
int adjval = 5;             //adjustment increment (adds or subtracts value given to analogwrite, 0-255)
int steerinval = 0;         //steer input value from receiver
int throtinval = 0;         //throttle input value from receiver
int steerinminpwm = 1000;   //minimum PWM value expected from steering channel on receiver
int steerinmaxpwm = 2000;   //maximum PWM value expected from steering channel on receiver
int throtinminpwm = 1000;   //minimum PWM value expected from throttle channel on receiver
int throtinmaxpwm = 2000;   //maximum PWM value expected from throttle channel on receiver
int sraw = 0;               //raw value being read from servo channel
int traw = 0;               //raw value being read from throttle channel
int zerooffsett = 50;       //PWM value offset, trims it so that 1500 is at zero
int zerooffsets = 50;       //PWM value offset, trims it so that 1500 is at zero
bool killallhumans = true;  //set killallhumans mode


#endif