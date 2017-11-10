/* This is the node on the arduino that will recieve values
from the jetson and run the electronics.
*/
#include <ros.h>
#include <std_msgs/Bool.h>

#include </home/ubuntu/sketchbook/libraries/ros_lib/shooter/Controls.h>

using namespace ros;

NodeHandle nh;

void controls_callback(const shooter::Controls& data){
  	if (data.shoot[0]){
		digitalWrite(13, HIGH);}
	else{
		digitalWrite(13, LOW);}
}


Subscriber<shooter::Controls> controls_sub("controls", &controls_callback);
void setup(){

	nh.initNode();
	nh.subscribe(controls_sub);
	pinMode(13, OUTPUT);
}

void loop(){
	nh.spinOnce();
	delay(50);
}

