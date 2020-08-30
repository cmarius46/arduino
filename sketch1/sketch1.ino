int motorPin = 7; 

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, HIGH);
  delay(5000);
  digitalWrite(motorPin, LOW);
}

void loop() {
}
