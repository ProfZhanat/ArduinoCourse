#include <Servo.h>

Servo serGrab1;
Servo serGrab2;
Servo serCore;
Servo serMiddle;

int curCore = 0;
int curMiddle = 90;


void setup() {
  serGrab1.attach(11);
  serGrab2.attach(10);
  serCore.attach(5);
  serMiddle.attach(6);
  
  serGrab1.write(0);
  serGrab2.write(180);
  serCore.write(0);
  serMiddle.write(90);
  
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  
}

void serialEvent() {
  String data = Serial.readString();
  if(data == "G")
  {
    grab(true);
  }
  else if(data == "S")
  {
    grab(false);
  }
  else if(parseDataX(data) == 1)
  {
    curCore += 5;
    serCore.write(curCore);
  }
  else if(parseDataX(data) == -1)
  {
    curCore -= 5;
    serCore.write(curCore);
  }
  else if(parseDataY(data) == 1)
  {
    curMiddle += 5;
    serMiddle.write(curMiddle);
  }
  else if(parseDataY(data) == -1)
  {
    curMiddle -= 5;
    serMiddle.write(curMiddle);
  }
}

int parseDataX(String data){
  data.remove(data.indexOf(":"));
  data.remove(data.indexOf("X"), 1);

  return data.toInt();
}

int parseDataY(String data){
  data.remove(0,data.indexOf(":") + 1);
  data.remove(data.indexOf("Y"), 1);

  return data.toInt();
  
}

void grab(bool really) {
  if(really)
  {
    serGrab1.write(70);
    serGrab2.write(110);
  }
  else
  {
    serGrab1.write(0);
    serGrab2.write(180);
  }
}
