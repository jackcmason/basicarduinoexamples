#include <Servo.h>

Servo extend;  //create servo objects
Servo angle;
Servo claw;
Servo rotate;

int const extendPin = A0; // potentiometer pins
int const anglePin = A1;
int const clawPin = A2;
int const rotatePin = A3;


int potVal;
int angledeg;  

void setup() {
  extend.attach(9); 
  angle.attach(10);
  claw.attach(11);
  rotate.attach(6);
  Serial.begin(9600); 
}

void loop() {
  potVal = analogRead(extendPin); 
  angledeg = map(potVal, 0, 1023, 0, 179);
  extend.write(angledeg);

  potVal = analogRead(anglePin); 
  angledeg = map(potVal, 0, 1023, 0, 179);
  angle.write(angledeg);

  potVal = analogRead(clawPin); 
  angledeg = map(potVal, 0, 1023, 0, 179);
  claw.write(angledeg);

  potVal = analogRead(rotatePin); 
  angledeg = map(potVal, 0, 1023, 0, 179);
  rotate.write(angledeg);
  
  delay(15);
}
