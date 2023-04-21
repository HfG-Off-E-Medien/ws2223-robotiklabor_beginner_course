 #include <Servo.h>
Servo myservo; 
String inByte; 
int d = 0;
 
 void setup() {
   myservo.attach(9);
   Serial.begin(9600);
   Serial.setTimeout(10); 
 }
 void loop() {
   if(Serial.available()>0) 
   {
    // If data is available to read,
     inByte = Serial.readString(); // read it and store it in val
     Serial.println(inByte);
     d = inByte.toInt();
     myservo.write(d);
   }
 }
