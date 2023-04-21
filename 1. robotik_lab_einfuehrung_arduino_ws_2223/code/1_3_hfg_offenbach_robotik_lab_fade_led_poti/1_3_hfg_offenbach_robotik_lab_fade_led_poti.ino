/*
  Fade LED with Poti

  Sketch written by Ivan Iovine
  The sketch was inspired by these arduino tutorial references:
  http://www.arduino.cc/en/Tutorial/Fade
  http://www.arduino.cc/en/Tutorial/AnalogInput
*/

int led = 9;           // the PWM pin the LED is attached to
int p = A0; // Potentiometer Analog Pin
int valueP = 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // map the potentiometer value from 0-1023 to 0-255 (LED has 255 values of brightness)
  valueP =  map(analogRead(p),0,1023,0,255);
  // Print to the serial Monitor the poti values
  Serial.println(valueP);
  // set the brightness of pin 9:
  analogWrite(led, valueP);
}
