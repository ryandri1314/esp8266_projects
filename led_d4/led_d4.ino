const short ledPin = D4;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
}
