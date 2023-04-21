int potPin = A3;

void setup() {
 Serial.begin(9600);
}

void loop() {

  // Read the Poti
  int potVal = analogRead(potPin);
  //Map the Poti values from 1023 to the max size of the Processing sketch
  potVal = map(potVal, 0, 1023, 0, 600);
  //Serial.println(potVal);
  
  // Sending Data to Processing via Serial Communication
  Serial.write(potVal);
  
   // Send data every 20 milliseconds
  //delay(20);
}
