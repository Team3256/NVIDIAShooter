/* This is the node on the arduino that will recieve values
from the jetson and run the electronics.
*/
#include <ros.h>
#include <std_msgs/String.h>

using namespace ros;

NodeHandle nh;

std_msgs::String str_msg;
Publisher chatter("chatter", &str_msg); 

char hello[13] = "hello world!";

void setup(){
	nh.initNode();
	nh.advertise(chatter);	
}

void loop(){
	str_msg.data=hello;
	chatter.publish(&str_msg);
	nh.spinOnce();
	delay(1);
}

