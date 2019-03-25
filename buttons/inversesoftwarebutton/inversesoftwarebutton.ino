//Progam for an LED to turn off
//when a button is pressed

int buttonPin = 2;
int ledPin = 13;

void setup() { //program setup
  pinMode(buttonPin, INPUT); //button is an input
  pinMode(ledPin, OUTPUT); //LED is an output

}

void loop() { //begin program
  if (digitalRead(buttonPin) == HIGH) { //if button is pressed
    digitalWrite(ledPin, LOW); //LED off
  } else {
    digitalWrite(13, HIGH); //LED on
  }

}
