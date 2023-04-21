int dirPin = 2;
int stepPin = 3;

boolean debugging = false;
int c = 0;


void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  Serial.begin(9600);
}
void loop() {
  c++;
  if(c < 1000)
  {
    if(debugging)
    {
      Serial.println("Forward");      
    }

    goForward();
  }
  else if(c > 5000 && c < 10000)
  {
    if(debugging)
    {
      Serial.println("Back");      
    }
    
    goBack();
  }
  else if(c > 11000)
  {
    if(debugging)
    {
      Serial.println("0");      
    }
    
    c = 0;
  }
}


void goForward()
{
  digitalWrite(dirPin, HIGH);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(1000);
}

void goBack()
{
  digitalWrite(dirPin, LOW);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
}
