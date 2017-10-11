// 717006@ Hallym University
// Seung-Chan Kim

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

// 어떻게 변화하는지 관찰
// A0 - GND
// A0 - 5V
// A0 - 3.3V

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
}
