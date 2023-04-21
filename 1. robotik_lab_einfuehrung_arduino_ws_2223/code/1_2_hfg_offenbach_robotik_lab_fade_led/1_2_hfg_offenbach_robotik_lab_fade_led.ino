/*
  Second Sketch in the Robotic Lab Course.
  
  Sketch written by Ivan Iovine
  The sketch was inspired by these arduino tutorial reference:
  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 9;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // set the brightness of pin 9:
  analogWrite(led, 20);
  delay(1000);
  analogWrite(led, LOW);
  delay(1000);
}
