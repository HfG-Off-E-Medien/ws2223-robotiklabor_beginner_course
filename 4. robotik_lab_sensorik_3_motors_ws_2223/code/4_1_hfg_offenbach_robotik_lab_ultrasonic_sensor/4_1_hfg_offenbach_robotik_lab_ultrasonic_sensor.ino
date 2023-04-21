/* 

Ultrasonic Sensor and LED Sketch
Written by Ivan Iovine

*/

//Define led 
int led = 10;

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
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 50)
  {
    digitalWrite(led, HIGH);
    delay(10);
  }
  else
  {
    digitalWrite(led, LOW);
    delay(10);
  }

  delay(50);

}
