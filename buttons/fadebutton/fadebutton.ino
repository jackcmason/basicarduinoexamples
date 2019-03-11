int pressed = 0;
int ledon = 0;
unsigned long fadetime = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(11, OUTPUT);
  delay(300);
}

void loop() {
  if(digitalRead(2) == HIGH && !pressed) {
    pressed = 1;
    ledon = !ledon;
    fadetime = millis();
  }
  if((digitalRead(2) == LOW) && pressed) {
    pressed = 0;
  }
  fadefunction(ledon, millis()-fadetime, 11, 100);
}

int fadefunction(int led, unsigned long starttime, int pin, int inc) {
  if ((starttime > 0 && starttime < 1*inc && led) || (starttime > 5*inc && !led)) {
    analogWrite(pin, 0);
  }
  if ((starttime > 1*inc && starttime < 2*inc && led) || (starttime > 4*inc && starttime < 5*inc && !led)) {
    analogWrite(pin, 50);
  }
  if ((starttime > 2*inc && starttime < 3*inc && led) || (starttime > 3*inc && starttime < 4*inc && !led)) {
    analogWrite(pin, 100);
  }
  if ((starttime > 3*inc && starttime < 4*inc && led) || (starttime > 2*inc && starttime < 3*inc && !led)) {
    analogWrite(pin, 150);
  }
  if ((starttime > 4*inc && starttime < 5*inc && led) || (starttime > 1*inc && starttime < 2*inc && !led)) {
    analogWrite(pin, 200);
  }
  if ((starttime > 5*inc && led) || (starttime > 0 && starttime < 1*inc && !led)) {
    analogWrite(pin, 255);
  }
  return 0;
}
