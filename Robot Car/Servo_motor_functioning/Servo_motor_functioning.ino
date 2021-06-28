#include<Servo.h>
Servo servoMain;

void setup() {
  servoMain.attach(10);
}

void loop() {
  servoMain.write(45);
  delay(1000);
  servoMain.write(0);
  delay(1000);
  servoMain.write(90);
  delay(1000);
  servoMain.write(135);
  delay(1000);
  servoMain.write(180);
  delay(1000);
  servoMain.write(90);
  delay(1000);
}
