// 717006@ Hallym University
// Seung-Chan Kim

import processing.serial.*;

Serial myPort;  // The serial port
int lf = 10;    // Linefeed in ASCII
String myString = null;

void setup() {
  
  size(800, 500);
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.clear();
  
}

// See https://processing.org/discourse/beta/num_1254511350.html
void draw() {
  while (myPort.available() > 0) {
    String str1  = myPort.readStringUntil(lf);
    
    if (str1 != null) 
    {
      print(str1);  // Prints String //<>//
      float num=float(str1);  // Converts and prints float
      //println(num);
      String buf = String.format("Sensor : %.2f", num); 
      
      background(255);  
      fill(0);   
      text(buf, 50,50);
    }
 
  }
  
}