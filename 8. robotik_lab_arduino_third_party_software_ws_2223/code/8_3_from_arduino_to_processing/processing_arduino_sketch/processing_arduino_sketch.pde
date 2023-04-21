import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
float nV;

void setup() 
{
  size(600, 600);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[1];
  println(Serial.list()[1]);
  myPort = new Serial(this, portName, 9600);
  
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
    //nV = map(val, 0, 255, 0, 600);
    //println(val);
    background(255);
    fill(255,200,200);           
    ellipse(val, 50, 30, 30);
  }
  
}
