// 717006
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Hallym University 20170921");
}

// the loop function runs over and over again forever
void loop() {
  
}

void serialEvent() {
  while (Serial.available()) {
    
    int v = Serial.read();
    if(v == '0')
    {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("LED ON");
    }
    else if(v== '1')
    {
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      Serial.println("LED OFF");
    }
   
    
  }

}



