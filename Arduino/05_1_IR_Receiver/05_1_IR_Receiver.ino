// IR Receiver test
// VS1838B
// based on 
// http://paste.ubuntu.com/8143467/
// https://eletroarduino.wordpress.com/tag/ir-receiver-module/
// Seung-Chan Kim

#include <IRremote.h>

int RECV_PIN = 2;
decode_results results;  
IRrecv irrecv(RECV_PIN);

#define BTN0 0xFF6897
#define BTN1 0xFF30CF
#define BTN2 0xFF18E7
#define BTN3 0xFF7A85
#define BTN4 0xFF10EF
#define BTN5 0xFF38C7
#define BTN6 0xFF5AA5
#define BTN7 0xFF42BD
#define BTN8 0xFF4AB5
#define BTN9 0xFF52AD
#define BTN100 0xFF9867
#define BTN200 0xFFB04F

#define BTN_H_0 0xC101E57B
#define BTN_H_1 0x9716BE3F
//TODO : add other buttons

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Hello");
}


void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    Serial.println(results.bits, DEC);
    
    switch(results.value)
    {
      case BTN0 :
      case BTN_H_0:  
        Serial.println("Button 0"); 
        break;
      case BTN1 :
      case BTN_H_1:    
        Serial.println("Button 1"); 
        break;
      default: break;
    
    }
    Serial.println("------------------");    
    irrecv.resume();
  }
}
