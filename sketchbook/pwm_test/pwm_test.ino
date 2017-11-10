#include <Servo.h>

#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5

#define TALON_CENTER_PULSE_US 1500
#define TALON_MIN_PULSE_US 1000
#define TALON_MAX_PULSE_US 2000
Servo lf, lb, rf, rb;

void run_motor(Servo motor, int power){
        power *= 100;
        int pulse_us = TALON_CENTER_PULSE_US + (5*power);
        if (pulse_us < TALON_MIN_PULSE_US) pulse_us = TALON_MIN_PULSE_US;
        if (pulse_us > TALON_MAX_PULSE_US) pulse_us = TALON_MAX_PULSE_US;
        motor.writeMicroseconds(pulse_us);
}

void setup(){
	lf.attach(TWO);
	rf.attach(THREE);
	lb.attach(FOUR);
	rb.attach(FIVE);
}

void loop(){
	run_motor(lf, 0.5);
	run_motor(rf, 0.5);
	run_motor(lb, 0.5);
	run_motor(rb, 0.5);
}
