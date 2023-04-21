/*
  2_2 Tracking Sensor Sketch
  Hfg Offenbach Robotic Lab
  Written by Ivan Iovine
*/

int t = 12;
int led = 10;

int tValue = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(led, OUTPUT);
  pinMode(t, INPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  tValue = digitalRead(t);
  Serial.println(tValue);

  if(tValue == 0)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
