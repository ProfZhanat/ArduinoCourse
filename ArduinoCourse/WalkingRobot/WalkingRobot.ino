#include<Servo.h>

Servo serRight;
Servo serLeft;
bool right = false;

String tempModify;

void setup() {

  serRight.attach(11);
  serLeft.attach(10);
  serRight.write(90);
  serLeft.write(90);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  serRight.write(0);
  serLeft.write(0);
  right = !right;
  delay(200);
  serRight.write(90);
  serLeft.write(90);
  delay(1000);
}
