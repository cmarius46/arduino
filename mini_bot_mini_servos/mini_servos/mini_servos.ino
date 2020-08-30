#include <Servo.h>

#define numberOfParts 5
#define MAX_ANGLE 170
#define MIN_ANGLE 10

Servo bodyServo;
Servo leftHandServo;
Servo rightHandServo;

int angle[numberOfParts];
// 0 -> body
// 1 -> left hand
// 2 -> right hand


void setupAngles() {
  angle[0] = 100;
  angle[1] = 0;
  angle[2] = 180;
  angle[3] = 70;
  angle[4] = 110;
}

char commands[numberOfParts][2];

void setupCommands() {
  commands[0][0] = 'd';
  commands[0][1] = 'a';
  commands[1][0] = 'f';
  commands[1][1] = 'r';
  commands[2][0] = 't';
  commands[2][1] = 'g';
  commands[3][0] = 'z';
  commands[3][1] = 'x';
  commands[4][0] = 'v';
  commands[4][1] = 'c';
}

Servo servo[numberOfParts];

void setupServos() {
  //bodyServo.attach(5);
  //bodyServo.write(0);
  servo[0].attach(5);
  servo[0].write(angle[0]);
  
  //leftHandServo.attach(6);
  //leftHandServo.write(0);
  servo[1].attach(6);
  servo[1].write(angle[1]);
  
  //rightHandServo.attach(11);
  //rightHandServo.write(0);
  servo[2].attach(11);
  servo[2].write(angle[2]);

  // left foot
  servo[3].attach(9);
  servo[3].write(angle[3]);

  //right foot
  servo[4].attach(10);
  servo[4].write(angle[4]);
  
}

void hail() {
  angle[1] = 160;
  angle[2] = 150;
  servo[1].write(angle[1]);
  servo[2].write(angle[2]);
}

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  delay(1000);
  
  setupAngles();
  setupServos();
  setupCommands();
  
}



char c;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    c = Serial.read();

    for(int i = 0; i < numberOfParts; ++i) {
      if(c == commands[i][0] && angle[i] <= MAX_ANGLE) {
        angle[i] += 10;
        servo[i].write(angle[i]);
      }
      else if(c == commands[i][1] && angle[i] >= MIN_ANGLE) {
        angle[i] -= 10;
        servo[i].write(angle[i]);
      }
    }
    if(c == 'q') {
      hail();
    }
    Serial.print(c);
  }
}
