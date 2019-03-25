//Use Programming to control an LED rather than having an LED 
//in series with a switch

int buttonPin = 2; //Arduino pin where the button is connected
int ledPin = 13; //Arduino pin where the LED is connected

void setup() { //setup pins
  pinMode(buttonPin, INPUT); //button is an input
  pinMode(ledPin, OUTPUT); //LED is an output

}

void loop() { //run program
  if (digitalRead(buttonPin) == HIGH) { //if the button is pressed
    digitalWrite(ledPin, HIGH); //LED on
  } else {
    digitalWrite(ledPin, LOW); //LED off
  }
}
