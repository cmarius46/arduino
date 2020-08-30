
#include <Servo.h>

Servo bodyServo;
Servo leftArmServo;
Servo rightArmServo;

void setup() {
  // put your setup code here, to run once:
  
  bodyServo.attach(3);
  leftArmServo.attach(6);
  rightArmServo.attach(11);
  
  Serial.begin(9600);
  
  bodyServo.write(90);
  leftArmServo.write(0);
  rightArmServo.write(0);
}

char k;
int bodyAngle = 0;
int leftArmAngle = 0;
int rightArmAngle = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    k = Serial.read();
    if(k == 'a' && bodyAngle < 180) {
      bodyAngle += 10;
      bodyServo.write(bodyAngle);  
    }
    else if(k == 'd' && bodyAngle > 0) {
      bodyAngle -= 10;
      bodyServo.write(bodyAngle);  
    }
    else if(k == 'r' && leftArmAngle < 180) {
      leftArmAngle += 10;
      leftArmServo.write(leftArmAngle); 
    }
    else if(k == 'f' && leftArmAngle > 0) {
      leftArmAngle -= 10;
      leftArmServo.write(leftArmAngle); 
    }
    else if(k == 't' && rightArmAngle < 180) {
      rightArmAngle += 10;
      rightArmServo.write(rightArmAngle); 
    }
    else if(k == 'g' && rightArmAngle > 0) {
      rightArmAngle -= 10;
      rightArmServo.write(rightArmAngle); 
    }
    Serial.print(k);
  }
}
