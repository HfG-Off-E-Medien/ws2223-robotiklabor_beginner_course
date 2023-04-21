int enA = 10;
int in1 =  6;
int in2 =  7;

int enB = 11;
int in3 = 8;
int in4 =  9;



void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {

  analogWrite(enA, 255); 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, 255); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(5000);
  //Reverse direction
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB, 255); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(5000);
}
