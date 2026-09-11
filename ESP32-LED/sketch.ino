const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(2000); // 2-second ON
  digitalWrite(ledPin, LOW);
  delay(1000); // 1-second OFF
}
