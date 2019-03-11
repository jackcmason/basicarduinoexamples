int pressed = 0;
int ledon = 0;
unsigned long toggletime;

void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  if(digitalRead(2) == HIGH && !pressed) {
    pressed = 1;
    ledon = !ledon;
    toggletime = millis();
  }
  if((digitalRead(2) == LOW) && pressed) {
    pressed = 0;
  }
  if(millis() - toggletime > 800) {
    digitalWrite(13, ledon);
  }
}
