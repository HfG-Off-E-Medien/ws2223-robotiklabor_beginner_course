int dirPin = 2;
int stepPin = 3;

int r = random(1,3);

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {

  if(r == 1)
  {
    goForward();
  }
  else if(r == 2)
  {
    goBack();
  }
  else
  {
    //
  }
  
}

void goForward() {
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(50);
  
}

void goBack() {
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(50);
  
}
