/* 

Ultrasonic Sensor Sketch
Written by Ivan Iovine

*/

#include <Servo.h>

//Define a servo variable
Servo myservo; 
int pos = 0;

void setup() {
  //define servo pin
  myservo.attach(9);
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  Serial.println("Servo 0");
  myservo.write(0);
  delay(1000);
  Serial.println("Servo 180");
  myservo.write(180);
  delay(1000);
}
