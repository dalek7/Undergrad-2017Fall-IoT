// 717006@ Hallym University
// Seung-Chan Kim
// Electret Mic Breakout Board by Sparkfun

int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
//  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("A0");
}

// Tested with these two sensors
// Electret Mic Breakout Board
// : https://learn.sparkfun.com/tutorials/electret-mic-breakout-board-hookup-guide
// MEMS Microphone
// : https://learn.sparkfun.com/tutorials/mems-microphone-hookup-guide

void loop() {
  sensorValue = analogRead(sensorPin);
  if(sensorValue>1023 || sensorValue<0) 
  return;
  
  double volts = (sensorValue * 3.3) / 1024;  // convert to volts
  
  Serial.println(volts);
}
