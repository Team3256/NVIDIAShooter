/* 
Tshirt Shooter Arduino Test Publisher
copyright 2016 
*/

#include <ros.h> //imports ROS
#include <std_msgs/String.h> //imports standard message string

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}
void loop()
{
  nh.spinOnce();
  delay(1000);
  str_msg.data = hello;
  chatter.publish( &str_msg );
}
