const int ledPin = 2;
unsigned long blinkCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  Serial.println("ESP32 LED Blink Program\nON: 2s | OFF: 1s");
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED Status: ON");
  delay(2000);

  digitalWrite(ledPin, LOW);
  Serial.println("LED Status: OFF");
  delay(1000);

  blinkCount++;
  Serial.print("Completed blink cycles: ");
  Serial.println(blinkCount);
}
