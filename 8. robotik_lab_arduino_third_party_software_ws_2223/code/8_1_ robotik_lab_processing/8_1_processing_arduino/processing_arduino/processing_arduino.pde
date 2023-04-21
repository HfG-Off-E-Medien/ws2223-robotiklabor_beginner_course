import processing.serial.*;

Serial myPort;  // Create object from Serial class
String inByteData;

void setup() 
{
  size(400,400);
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  print(Serial.list());
}

void draw() {
  
  fill(0,255,0);
  rect(50,100,100,100);
  
  fill(255,0,0);
  rect(250,100,100,100);
  
  if (mouseX > 50 && mouseX < 150 && mouseY > 100 && mouseY < 200) 
  {
   inByteData = "On";
   myPort.write(inByteData);
   println(inByteData);

  } 
  else if (mouseX > 250 && mouseX < 350 && mouseY > 100 && mouseY < 200) 
  {
   inByteData = "Off";
   myPort.write(inByteData);
   println(inByteData);
  }
  else
  {
    myPort.write(" ");
  }
}
