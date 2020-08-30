#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(3);
}

void loop() {
  myServo.write(180);
  delay(3000);
  myServo.write(0);
  delay(5000);
  // put your main code here, to run repeatedly:
}
