// 717007
// Arduino의 Built-in LED를 Touch sensor로 제어하기
// Seung-Chan Kim

int pin1 = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1, INPUT); 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int touchValue = digitalRead(pin1);
  digitalWrite(LED_BUILTIN, touchValue);

  Serial.println(touchValue);
  delay(1);        // delay in between reads for stability

}
