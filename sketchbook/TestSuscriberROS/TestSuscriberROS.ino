
#include <ros.h>
#include <std_msgs/UInt16.h>

using namespace ros;
NodeHandle nh;
void callback(const std_msgs::UInt16& data){
  int ans = data.data;
  digitalWrite(13,HIGH);
  delay(ans*1000);
  digitalWrite(13,LOW);
}
Subscriber<std_msgs::UInt16> sub("test", &callback);
void setup(){
  pinMode(13,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
