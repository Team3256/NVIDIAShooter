/* This is the node on the arduino that will recieve values
from the jetson and run the electronics.
*/
#include <Servo.h>
#include <Encoder.h>
#include "/home/ubuntu/sketchbook/libraries/Encoder/Encoder.h"

#include <ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>

#define LED 13

#define LEFT_SHOOT_PIN 52
#define RIGHT_SHOOT_PIN 53

#define LEFT_POP_FORWARD 28
#define LEFT_POP_REVERSE 26 
#define RIGHT_POP_FORWARD 24
#define RIGHT_POP_REVERSE 22

#define LEFT_EJECT_FORWARD 27 
#define LEFT_EJECT_REVERSE 29 
#define RIGHT_EJECT_FORWARD 23
#define RIGHT_EJECT_REVERSE 25 

#define LEFT_SHOOT 30
#define RIGHT_SHOOT 31

#define LEFT_FRONT_PIN 2
#define LEFT_BACK_PIN 3
#define RIGHT_FRONT_PIN 4
#define RIGHT_BACK_PIN 5
#define PIVOT_PIN 10

//TODO: ASSIGN PORT NUMBERS
#define HALL_EFFECT 20
#define ENCODER_A 18 
#define ENCODER_B 19

#define TALON_CENTER_PULSE_US 1500
#define TALON_MIN_PULSE_US 1000
#define TALON_MAX_PULSE_US 2000

using namespace ros;

Encoder pivotEnc(ENCODER_A, ENCODER_B);

Servo left_front;
Servo left_back;
Servo right_front;
Servo right_back;
Servo pivot;

NodeHandle nh;

std_msgs::Float32MultiArray sensorVals;
std_msgs::Float32 debug_msg;
ros::Publisher pub("sensors",&sensorVals);
ros::Publisher debug("debug", &debug_msg);

bool is_left_reloading = false;
bool is_right_reloading = false;
long pivotPos = -999;

void run_motor(Servo motor, double power){
	power *= 100;
	int pulse_us = TALON_CENTER_PULSE_US + (5*power);
	if (pulse_us < TALON_MIN_PULSE_US) pulse_us = TALON_MIN_PULSE_US;
	if (pulse_us > TALON_MAX_PULSE_US) pulse_us = TALON_MAX_PULSE_US;
	motor.writeMicroseconds(pulse_us); 
}

void shoot(){
	//TODO: implement
}

void pop_left(){
	digitalWrite(LEFT_POP_FORWARD, HIGH);	
	digitalWrite(LEFT_POP_REVERSE, LOW);
}

void pop_right(){
	digitalWrite(RIGHT_POP_FORWARD, HIGH);
	digitalWrite(RIGHT_POP_REVERSE, LOW);
}

void push_left(){
	digitalWrite(LEFT_POP_FORWARD, LOW);
	digitalWrite(LEFT_POP_REVERSE, HIGH);
}

void push_right(){
	digitalWrite(RIGHT_POP_FORWARD, LOW); 
	digitalWrite(RIGHT_POP_REVERSE, HIGH);
}

void eject_left(){
	digitalWrite(LEFT_EJECT_FORWARD, HIGH);
	digitalWrite(LEFT_EJECT_REVERSE, LOW);
}

void eject_right(){
	digitalWrite(RIGHT_EJECT_FORWARD, HIGH);
	digitalWrite(RIGHT_EJECT_REVERSE, LOW);
}

void retract_left(){
	digitalWrite(LEFT_EJECT_FORWARD, LOW);
	digitalWrite(LEFT_EJECT_REVERSE, HIGH);
}

void retract_right(){
	digitalWrite(RIGHT_EJECT_FORWARD, LOW);
	digitalWrite(RIGHT_EJECT_REVERSE, HIGH);	
}
void shoot_right(int wait){
	digitalWrite(RIGHT_SHOOT, LOW);
	delay(wait);
	digitalWrite(RIGHT_SHOOT, HIGH);
}
void shoot_left(int wait){
	digitalWrite(LEFT_SHOOT, LOW);
	delay(wait);
	digitalWrite(LEFT_SHOOT, HIGH);
} 

bool hallEffect(){
	return !digitalRead(HALL_EFFECT);
}

void controls_callback(const std_msgs::Float32MultiArray& data){
	float left_drive = data.data[0];
	float right_drive = data.data[1];
	float pivot_power = data.data[2];
	bool left_shoot = data.data[3] != 0;
	bool right_shoot = data.data[4] != 0;
	bool left_reload = data.data[5] != 0;
	bool right_reload = data.data[6] != 0;	
	bool pivot_forward = data.data[7] != 0;
	bool pivot_backward = data.data[8] != 0;	
	float jetson_time = data.data[9];

	//run drive
	run_motor(left_front, left_drive);	
	run_motor(left_back, left_drive);
	run_motor(right_front, -right_drive);
	run_motor(right_back, -right_drive);

	//shoot
	if (left_shoot){
		shoot_left(60);
	}
	if (right_shoot){
		shoot_right(60);
	}
	
	pivot_power = pivot_backward ? pivot_power*-1 : pivot_power;

	//run pivot
	if (pivotPos > 3000){
		pivot_power = min(pivot_power, 0);	
	}
	else if (pivotPos < -3000){
		pivot_power = max(pivot_power, 0);
	}
	if (pivot_forward || pivot_backward){
		run_motor(pivot, pivot_power);
	} 
	else {
		run_motor(pivot, 0);
	}
	debug_msg.data = pivot_power;
	debug.publish( &debug_msg);
	
	//automatic reloading
	if (left_reload && !is_left_reloading){
		is_left_reloading = true;
		pop_left();	
		delay(500);
		eject_left();
		delay(500);
		retract_left();
		delay(500);
		push_left();
		is_left_reloading = false;
	}
	
	if (right_reload && !is_right_reloading){
		is_right_reloading = true;
		pop_right();	
		delay(500);
		eject_right();
		delay(500);
		retract_right();
		delay(500);
		push_right();
		is_right_reloading = false;
	}
}

Subscriber<std_msgs::Float32MultiArray> sub("controls", &controls_callback);

void setup(){

	left_front.attach(LEFT_FRONT_PIN);
	left_back.attach(LEFT_BACK_PIN);
	right_front.attach(RIGHT_FRONT_PIN);
	right_back.attach(RIGHT_BACK_PIN);
	pivot.attach(PIVOT_PIN);
	
	sensorVals.data[1] = pivotPos;	
	pinMode(LED, OUTPUT);
	pinMode(HALL_EFFECT, INPUT);

	pinMode(LEFT_POP_FORWARD, OUTPUT);
	pinMode(LEFT_POP_REVERSE, OUTPUT);
	pinMode(RIGHT_POP_FORWARD, OUTPUT);
	pinMode(RIGHT_POP_REVERSE, OUTPUT);

	pinMode(LEFT_EJECT_FORWARD, OUTPUT);
	pinMode(LEFT_EJECT_REVERSE, OUTPUT);
	pinMode(RIGHT_EJECT_FORWARD, OUTPUT);
	pinMode(RIGHT_EJECT_REVERSE, OUTPUT);

	pinMode(LEFT_SHOOT, OUTPUT);
	pinMode(RIGHT_SHOOT, OUTPUT);
	
	//close electronic solenoids
	digitalWrite(LEFT_SHOOT, HIGH);
	digitalWrite(RIGHT_SHOOT, HIGH);

	// set barrel and ejectors to default(shooting) position
	retract_left();
	retract_right();
	pop_left();
	pop_right();

	sensorVals.data_length = 2;

	nh.initNode();
	nh.advertise(pub);
	nh.advertise(debug);
	nh.subscribe(sub);
	
}

void loop(){
	//Update 
	pivotPos = pivotEnc.read();

	//update sensor topic
	if (hallEffect()){
		pivotEnc.write(0);
		sensorVals.data[0] = 1.0;
	} else {
		sensorVals.data[0] = 0.0;
	}
	sensorVals.data[1] = pivotPos;
	pub.publish( &sensorVals);
	
	nh.spinOnce();
	delay(50);
}

