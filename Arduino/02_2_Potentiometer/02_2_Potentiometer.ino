// 717007
// Reading a Potentiometer
// https://cdn.sparkfun.com/assets/learn_tutorials/3/1/0/Arduino_circuit_02-v3_2.png

int ledPin = 2;      // The LED is connected to digital pin 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability

  
  digitalWrite(ledPin, HIGH);     // Turn the LED on

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds
                                  
  digitalWrite(ledPin, LOW);      // Turn the LED off

  delay(sensorValue);             // Pause for sensorValue
                                  // milliseconds
                                  

}
