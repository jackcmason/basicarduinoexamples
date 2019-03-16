int sensorValue = 0; //stores sensor data
float volts = 0; //holds voltage conversion

void setup() {
  Serial.begin(9600); //init serial
}

void loop() {
  sensorValue = analogRead(A0); //read sensor
  volts = 5.0*(sensorValue/1023.0); //convert sensor value to volts
  Serial.println(volts); //print voltage
  delay(500); //wait 0.5 seconds
}
