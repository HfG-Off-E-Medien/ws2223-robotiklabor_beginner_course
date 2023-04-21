 String inByte; 
 int ledPin = 11; 
 
 void setup() {
   pinMode(ledPin, OUTPUT); 
   Serial.begin(9600);
   Serial.setTimeout(10); 
 }
 void loop() {
   if(Serial.available()>0) 
   {
    // If data is available to read,
     inByte = Serial.readString(); // read it and store it in val
     Serial.println(inByte);

     if (inByte == "On") 
     { 
       digitalWrite(ledPin, HIGH);
     } 
     else if (inByte == "Off") 
     {
       digitalWrite(ledPin, LOW); 
     }
     else
     {
       //
     }
   }
}
