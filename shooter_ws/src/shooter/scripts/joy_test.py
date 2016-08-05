#!/usr/bin/env python
import rospy
from shooter.msg import JoyValues
from std_msgs.msg import Float32
def arcade_drive(throttle, turn):
	left = int(throttle)+int(turn)
	right = int(throttle)+int(turn)
	speeds = []
	speeds.append(left)
	speeds.append(right)
	return speeds
def callback(data):
	#Joyvals
	#These values are being fed from the joystick axes
	throttle = data.axis_vals[0]
	turn = data.axis_vals[1]
def run_node():
	rospy.init_node('joystick_test',anonymous=True)
	#need to have publisher to publish joy values in other place
	rospy.Subscriber('joy', JoyValues, callback)
	rospy.spin()
if __name__ == '__name__':
	try:
		run_node()
	except rospy.ROSInterruptException: pass
