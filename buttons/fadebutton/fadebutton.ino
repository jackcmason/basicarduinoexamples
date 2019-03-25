int pressed = 0; //is the button pressed? 0 is no, 1 is yes
int ledon = 0; //is the LED on? 0 is no, 1 is yes
unsigned long fadetime = 0; //what time was the LED toggled? (ms since program start)
int buttonPin = 2; //Arduino pin button is connected to
int ledPin = 11; //Arduino pin LED is connected to (needs to be a PWM pin)

void setup() { //program setup
  pinMode(buttonPin, INPUT); //button is an input
  pinMode(ledPin, OUTPUT); //button is an output
  delay(300);
}

void loop() {
  //if button was pressed and was not previously pressed
  if (digitalRead(buttonPin) == HIGH && !pressed) {
    pressed = 1; //button was pressed
    ledon = !ledon; //toggle LED
    fadetime = millis(); //store time
  }
  if ((digitalRead(2) == LOW) && pressed) { //if button is not pressed and was pressed previously
    pressed = 0; //button is not pressed
  }
  fadefunction(ledon, millis() - fadetime, 11, 100); //adjust LED brightness
}

//function which handles LED fading
//takes led state to determine if it is fading on or off
//takes time since led toggle to determine which part of the "fade cycle" is occuring
//takes pin number (LED pin) to determine which pin to act on
//takes a duration to determine how long each phase of the fade should last
int fadefunction(int led, unsigned long starttime, int pin, int inc) {
  if ((starttime > 0 && starttime < 1 * inc && led) || (starttime > 5 * inc && !led)) {
    analogWrite(pin, 0);
  }
  if ((starttime > 1 * inc && starttime < 2 * inc && led) || (starttime > 4 * inc && starttime < 5 * inc && !led)) {
    analogWrite(pin, 50);
  }
  if ((starttime > 2 * inc && starttime < 3 * inc && led) || (starttime > 3 * inc && starttime < 4 * inc && !led)) {
    analogWrite(pin, 100);
  }
  if ((starttime > 3 * inc && starttime < 4 * inc && led) || (starttime > 2 * inc && starttime < 3 * inc && !led)) {
    analogWrite(pin, 150);
  }
  if ((starttime > 4 * inc && starttime < 5 * inc && led) || (starttime > 1 * inc && starttime < 2 * inc && !led)) {
    analogWrite(pin, 200);
  }
  if ((starttime > 5 * inc && led) || (starttime > 0 && starttime < 1 * inc && !led)) {
    analogWrite(pin, 255);
  }
  return 0;
}
