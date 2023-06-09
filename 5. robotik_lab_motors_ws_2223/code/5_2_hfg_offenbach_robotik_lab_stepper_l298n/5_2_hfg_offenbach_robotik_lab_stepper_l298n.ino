// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup()
{
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() 
{
  // Set the speed
  //myStepper.setSpeed(20);
  // step one revolution in one direction:
  //Serial.println("clockwise");
  //myStepper.step(stepsPerRevolution);
  //delay(500);

  // Set the speed
  myStepper.setSpeed(60);
  //step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
