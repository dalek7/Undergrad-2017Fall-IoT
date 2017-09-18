int ledStatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  ledStatus = digitalRead(13);
  
  Serial.println(ledStatus);
  digitalWrite(13,  !ledStatus);  

  delay(1000);           
 
}
