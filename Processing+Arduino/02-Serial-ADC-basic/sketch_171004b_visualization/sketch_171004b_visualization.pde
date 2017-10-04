// 717006@ Hallym University
// Seung-Chan Kim
// Advanced display

import processing.serial.*;

Serial myPort;  // The serial port
int lf = 10;    // Linefeed in ASCII
String myString = null;

float[] keep_val1;
int nSample = 200;

void setup() {
  
  keep_val1 = new float[nSample];
  for(int i=0; i<nSample; i++)
  {
    keep_val1[i] = 0.0;
  }
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
      
      float num=float(str1);  // Converts and prints float
      //println(num);
      ShiftWithNewf(keep_val1, num);
      background(255);  
      fill(0);   
      
      String buf;
      buf = String.format("Sensor : INMP401 (InvenSense)"); 
      text(buf, 50,50);
      buf = String.format("Current Value : %.2f", num); 
      text(buf, 50,70);
      
      buf = String.format("https://github.com/dalek7/Undergrad-2017Fall-IoT/");
      text(buf, 50,90);
      
      
      int offset_x1 = 100;
      int offset_y1 = 200;
      float g = 10;
      float gx = 2;
      for(int i=0; i<nSample-1; i++)
      {
        int y1 = int(offset_y1 + g* keep_val1[i]) - 0;
        int y2 = int(offset_y1 + g* keep_val1[i+1]) - 0;
        line(offset_x1 + gx*i, y1, offset_x1 + gx*(i+1), y2);
        
      }
      
      
      /*
      for(int i=0; i<50; i++)
      {
        String tmp1 = String.format("%.2f", keep_val1[i]);
        text(tmp1, 20, 60+ 15*i);
      }
      */
      
    }
 
  }
  
}




float GetMean(float[] arr)
{
  int sz = arr.length;
  int i;
  float sum =0;
  for(i=0; i< sz; i++)
  {
    sum = sum + arr[i];
  }
  
  float mean = sum / float(i);
  return mean;
}


void ShiftWithNewf(float[] arr, float n_val)
{
  int sz = arr.length;
  int i;
  for(i=0; i< sz-1; i++)
  {
    arr[sz-1-i] = arr[sz-2-i];
    
  }

  arr[0] = n_val;

}