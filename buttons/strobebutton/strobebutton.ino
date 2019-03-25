//program which flashes LED when
//button is pressed

int buttonPin = 2; //Arduino pin where button is attached
int ledPin = 13; //Arduino pin where LED is attached

void setup() { //program setup
  pinMode(buttonPin, INPUT); //button is an input
  pinMode(ledPin, OUTPUT); //LED is an output

}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { //if button is pressed
    if((millis() % 125) < 63) { //LED on and off in controlled intervals
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  } else {
    digitalWrite(13, LOW); //LED off
  }

}
