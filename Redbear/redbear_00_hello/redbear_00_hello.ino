// https://www.youtube.com/watch?v=d75strWav5k
// https://github.com/redbear/nRF5x/tree/master/nRF51822/arduino

void setup() {
  // put your setup code here, to run once:

  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, LOW);
  delay(100);

  digitalWrite(13, HIGH);
  delay(1000);

}
