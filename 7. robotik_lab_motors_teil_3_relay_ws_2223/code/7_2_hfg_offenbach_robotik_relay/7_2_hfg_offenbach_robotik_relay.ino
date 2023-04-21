 int c = 10;

void setup() {
  //Init Pin
  pinMode(c, OUTPUT);
}

void loop() {
  digitalWrite(c, HIGH);
  delay(1000);
  digitalWrite(c, LOW);
  delay(1000);
}
