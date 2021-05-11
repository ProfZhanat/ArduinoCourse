#include<Servo.h>

Servo ser;

void setup() {

  ser.attach(11);
  Serial.begin(9600);
}

void loop() {
  ser.write(map(analogRead(A0), 0, 1023, 0, 180));
}
}
