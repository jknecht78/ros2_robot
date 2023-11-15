#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver myServos = Adafruit_PWMServoDriver();

#define SERVOMIN  150
#define SERVOMAX  600

int current_x = (SERVOMIN + SERVOMAX) / 2;
int current_y = (SERVOMIN + SERVOMAX) / 2;

uint8_t servonum = 0;
uint8_t numberOfServos = 16;

void setup() {
  myServos.begin();
  myServos.setPWMFreq(60);
  delay(10);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n'); 
    int commaIndex = data.indexOf(',');
    int x = data.substring(0, commaIndex).toInt(); 
    int y = data.substring(commaIndex + 1).toInt(); 
    yourFunction(x, y);
  }
}

void yourFunction(int x, int y) {
  if ( (x < 0) and (current_x - 1 > SERVOMIN) ) {
    current_x--;
  }

  if ( (y < 0) and (current_y - 1 > SERVOMIN) ) {
    current_y--;
  }

  if ( (x > 0) and (current_x + 1 < SERVOMAX) ) {
    current_x++;
  }

  if ( (y > 0) and (current_y + 1 < SERVOMAX) ) {
    current_y++;
  }

  if ( x != 0) {
    myServos.setPWM(0, 0, current_x);
  }
  
  if ( y != 0) {
    myServos.setPWM(1, 0, current_y);
  }
}