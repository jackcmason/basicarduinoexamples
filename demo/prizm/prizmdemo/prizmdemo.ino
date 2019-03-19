#include <PRIZM.h>      // include PRIZM library
PRIZM prizm;            // instantiate a PRIZM object “prizm” so we can use its functions
long lasttime = 0;
int dir = -10;
int ultrasonicpin = 4;
int servo = 2;
int altservo = 1;

void setup() {

  prizm.PrizmBegin();           // initialize PRIZM
  prizm.setMotorInvert(1,1);    // invert the direction of DC Motor 1 to harmonize direction
  prizm.setServoSpeed(servo,75);
  prizm.setServoSpeed(altservo,25);
                              
}

void loop() {
  if (prizm.readSonicSensorCM(ultrasonicpin) < 10 && millis() > lasttime + 1000) {
    //prizm.setMotorPowers(0, 0);
    lasttime = millis();
    prizm.setServoPosition(servo,150);
    dir = dir * -1;
  } else {
    prizm.setMotorPowers(dir, 0); 
  }
  if (millis() > lasttime + 300) {
    prizm.setServoPosition(servo,60);
  }

  if(millis() > lasttime + 1800 && millis() < lasttime + 1900) {
    prizm.setServoPosition(altservo,30);
  }
  if(millis() > lasttime + 2900 && millis() < lasttime + 3000) {
    prizm.setServoPosition(altservo,120);
  }
}
