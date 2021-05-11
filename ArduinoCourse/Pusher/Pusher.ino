#include <Servo.h>

#define Echo 7
#define Trig 8

Servo serPush;
 
unsigned int impulseTime=0; 
unsigned int distance_sm=0; 
 
void setup() 
{  
  pinMode(Trig, OUTPUT); // инициируем как выход 
  pinMode(Echo, INPUT); // инициируем как вход 
  serPush.attach(11);
  serPush.write(180);
  Serial.begin(9600);
} 
 
void loop() 
{  
  digitalWrite(Trig, HIGH); 
  /* Подаем импульс на вход trig дальномера */
  delayMicroseconds(10); // равный 10 микросекундам 
  digitalWrite(Trig, LOW); // Отключаем 
  impulseTime=pulseIn(Echo, HIGH); // Замеряем длину импульса 
  distance_sm=impulseTime/58; // Пересчитываем в сантиметры 
  if(distance_sm < 10)
  {
    serPush.write(140);
    delay(100);
    serPush.write(180);
    delay(100);
  }
  Serial.println(distance_sm); // Выводим на порт
  delay(100); 
  /* ждем 0.1 секунды, Следующий импульс может быть излучён, только после исчезновения эха от предыдущего. 
   Это время называется периодом цикла (cycle period). 
   Рекомендованный период между импульсами должен быть не менее 50 мс.  */
}
