/* This is the node on the arduino that will recieve values
from the jetson and run the electronics.
*/
#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Bool.h>
#define spike1_pin1 2 //signal (white PWM wire)
#define spike1_pin2 4 //power (red PWN wire)
#define spike2_pin1 7 //signal (white PWM wire)
#define spike2_pin2 8 //power (red PWN wire)

#define leftMotor1_pin 3
#define leftMotor2_pin 5
#define rightMotor1_pin 6
#define rightMotor2_pin 9

#define manifoldTest1_pin 12
#define manifoldTest2_pin 13

using namespace ros;

Servo leftMotor1;
Servo leftMotor2;
Servo rightMotor1;
Servo rightMotor2;
NodeHandle nh;
#ifdef TEST
  void spike_callback(const std_msgs::UInt16& msg){
  int a = msg.data;
  if (a==1){
      digitalWrite(13,HIGH);
      digitalWrite(spike1_pin1, HIGH);
      digitalWrite(spike1_pin2, LOW);
      delay(30);
    }
    digitalWrite(13,HIGH);
    digitalWrite(spike1_pin1, LOW);
    digitalWrite(spike1_pin2, LOW);
}
Subscriber<std_msgs::UInt16> spike_sub("shoot", &spike_callback);
#endif TEST
int A,B;
#ifdef tank
void tankDrive(int left, int right){
  int leftSpeed = 1500 + (5*left);
  int rightSpeed = 1500 + (-5*right);
  leftMotor1.writeMicroseconds(leftSpeed);
  leftMotor2.writeMicroseconds(leftSpeed);
  rightMotor1.writeMicroseconds(rightSpeed);
  rightMotor2.writeMicroseconds(rightSpeed);
}
#endif tank
void runLMotor(int left){
  int leftSpeed = 1500 + (5*left);
  leftMotor1.writeMicroseconds(leftSpeed);
  leftMotor2.writeMicroseconds(leftSpeed);
}
void runRMotor(int right){
  int rightSpeed = 1500 + (-5*right);
  rightMotor1.writeMicroseconds(rightSpeed);
  rightMotor2.writeMicroseconds(rightSpeed);
}
#ifdef oldshoot
void shoot(boolean left, boolean right, int wait){
  if (left){
    digitalWrite(spike1_pin1, HIGH);
    digitalWrite(spike1_pin2, LOW); 
  }
  if(right){
    digitalWrite(spike2_pin1, HIGH);
    digitalWrite(spike2_pin2, LOW);
  }
  delay(wait);
  digitalWrite(spike1_pin1, LOW);
  digitalWrite(spike1_pin2, LOW); 
  digitalWrite(spike2_pin1, LOW);
  digitalWrite(spike2_pin2, LOW); 
}
#endif oldshoot
void shootL(boolean left, int wait){
 if (left){
   digitalWrite(spike1_pin1, HIGH);
   digitalWrite(spike1_pin2, LOW); 
   
  delay(wait);
 }
  digitalWrite(spike1_pin1, LOW);
  digitalWrite(spike1_pin2, LOW); 
  digitalWrite(spike2_pin1, LOW);
  digitalWrite(spike2_pin2, LOW);
 return; 
}
void shootR(boolean right, int wait){
  if (right){
   digitalWrite(spike2_pin1, HIGH);
   digitalWrite(spike2_pin2, LOW); 
  delay(wait);
 }
  digitalWrite(spike1_pin1, LOW);
  digitalWrite(spike1_pin2, LOW); 
  digitalWrite(spike2_pin1, LOW);
  digitalWrite(spike2_pin2, LOW); 
 return;
}
void lmcallback(const std_msgs::Float32& msg){
  double left_speed = msg.data;
  runLMotor(left_speed);
}
void rmcallback(const std_msgs::Float32& msg){
  double right_speed = msg.data;
  runRMotor(right_speed);
}
void lbcallback(const std_msgs::Bool& msg){
  boolean b = msg.data;
  shootL(b,30);
}
void rbcallback(const std_msgs::Bool& msg){
  boolean b = msg.data;
  shootR(b,30);
}
Subscriber<std_msgs::Float32> lmotor_sub("l_motor", &lmcallback);
Subscriber<std_msgs::Float32> rmotor_sub("r_motor", &rmcallback);
Subscriber<std_msgs::Bool> lbarrel_sub("l_barrel", &lbcallback);
Subscriber<std_msgs::Bool> rbarrel_sub("r_barrel", &rbcallback);

void setup(){
  pinMode(spike1_pin1, OUTPUT);
  pinMode(spike1_pin2, OUTPUT);
  pinMode(spike2_pin1, OUTPUT);
  pinMode(spike2_pin2, OUTPUT);
  
  pinMode(manifoldTest1_pin, OUTPUT);
  pinMode(manifoldTest2_pin, OUTPUT);
  
  leftMotor1.attach(leftMotor1_pin);
  leftMotor2.attach(leftMotor2_pin);
  rightMotor1.attach(rightMotor1_pin);
  rightMotor2.attach(rightMotor2_pin);

  nh.initNode();
  nh.subscribe(lmotor_sub);
  nh.subscribe(rmotor_sub);
  nh.subscribe(lbarrel_sub);
  nh.subscribe(rbarrel_sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}

