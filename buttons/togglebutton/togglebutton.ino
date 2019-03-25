//program to toggle an LED on button press 
//rather than holding the button to keep the LED on

int pressed = 0; //is the button pressed? 0 is no, 1 is yes
int ledon = 0; //is the LED on? 0 is no, 1 is yes
unsigned long toggletime; //time when the LED was toggled (in ms from program start)
int buttonPin = 2; //Arduino pin where button is connected
int ledPin = 13; //Arduino pin where LED is connected

//program setup
void setup() {
  pinMode(buttonPin, INPUT); //button is an input
  pinMode(ledPin, OUTPUT); //LED is an output

}

//run program
void loop() {
  //if button was pressed and wasn't previously pressed
  if(digitalRead(buttonPin) == HIGH && !pressed) {
    pressed = 1; //button was pressed
    ledon = !ledon; //toggle LED state
    toggletime = millis(); //store time when LED toggled
  }
  //if button is no longer pressed and was previously pressed
  if((digitalRead(buttonPin) == LOW) && pressed) {
    pressed = 0; //button isn't pressed
  }
  digitalWrite(ledPin, ledon);
}
