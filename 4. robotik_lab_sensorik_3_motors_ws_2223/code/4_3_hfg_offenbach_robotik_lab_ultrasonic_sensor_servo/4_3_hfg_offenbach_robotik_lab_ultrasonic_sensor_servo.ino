/* 

Ultrasonic Sensor Sketch
Written by Ivan Iovine

*/

#include <Servo.h>

//Define a servo variable
Servo myservo; 
int pos = 0;

// Define Trig and Echo pin:
int trigPin = 3;
int echoPin = 2;

// Define variables:
long duration; // long is a variable that can have more digits than int
int distance;
float speedSound = 0.034;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //define servo pin
  myservo.attach(9);
  
  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance:
  distance = duration * speedSound / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  //Serial.print("Distance = ");
  //Serial.print(distance);
  //Serial.println(" cm");

  if(distance < 50)
  {
    Serial.println("Servo 180");
    myservo.write(180);
    delay(10);
  }
  else
  {
    Serial.println("Servo 0");
    myservo.write(0);
    delay(10);
  }

  delay(50);

}
