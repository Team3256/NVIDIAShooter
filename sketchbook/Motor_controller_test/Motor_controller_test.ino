#include <Servo.h>
#define PIN 9
Servo test;
int s = 2032;
int mini = 1003;
void setup(){
  //3000,100000
  test.attach(PIN);
  Serial.begin(9600);
}
void loop(){
  test.writeMicroseconds(mini);
  Serial.println(s);
  delay(1000);
}
