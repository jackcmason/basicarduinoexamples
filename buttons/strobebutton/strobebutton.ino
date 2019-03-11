void setup() {
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  if (digitalRead(2) == HIGH) {
    if((millis() % 125) < 63) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  } else {
    digitalWrite(13, LOW);
  }

}
