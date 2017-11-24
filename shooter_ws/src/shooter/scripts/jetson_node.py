#!/usr/bin/env python
import rospy
import math

#ROS msg files we are using
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Joy

#bools to keep track of button isPressed
#without this, the solenoids will be kept open while the trigger is held, releasing too much air and shooting further
old_lshoot = False
old_rshoot = False
old_lreload = False
old_rreload = False

#takes in two joystick values and outputs the left and right power levels for arcade drive
def arcadeDrive(throttle,turn):
	
	#basic arcade drive without skim
	left = throttle + turn
	right = throttle - turn
	
	#clip the left and right values between -1 and 1
	left = 1 if left > 1 else left
	left = -1 if left < -1 else left
	right = 1 if right > 1 else right
	right = -1 if right < -1 else right	
	
	#clip values less than 0.25 to prevent "drifting"
	if math.fabs(left) < 0.25:
		left = 0
	if math.fabs(right) < 0.25:
		right = 0
		
	#Halve driving power just for safety	
	left = left*0.5
	right = right*0.5
	return left,right

#Callback function when a joy msg is received. Most of code is here
def callback(data):
	global old_lreload
	global old_rreload
	global old_lshoot
	global old_rshoot
	
	#array of values we send to Arduino
	array = Float32MultiArray()
	
	#Arcade Drive
	ldrive,rdrive = arcadeDrive(float(data.axes[1]),float(-data.axes[2]))

	#set values for the arduino from joystick input
	lshoot = 1 if float(data.axes[8]) > 0.5 else 0
	rshoot = 1 if float(data.axes[9]) > 0.5 else 0
	lshoot = lshoot and not old_lshoot
	rshoot = rshoot and not old_rshoot
	
	lbumper = int(data.buttons[10])
	rbumper = int(data.buttons[11])

	lreload = int(data.buttons[15])
	lreload = lreload and not old_lreload
	rreload = int(data.buttons[13])
	rreload = rreload and not old_rreload

	pivotForward = int(data.buttons[12])
	pivotBackward = int(data.buttons[14])	

	#populate and publish the array (note: it's limited to 10 values. If more are needed, make another topic or use custom messages)
	array.data = [ldrive,rdrive,lshoot,rshoot,lreload,rreload,pivotForward,pivotBackward, lbumper, rbumper]
	controls_pub.publish(array)	
	
	#set "old" values for the isPressed feature
	old_lreload = lreload
	old_rreload = rreload
	old_lshoot = lshoot	
	old_rshoot = rshoot

def main():
	rospy.init_node('ShooterNode')
	global controls_pub
	#creates publisher that publishes values to the Arduino
	controls_pub = rospy.Publisher('controls', Float32MultiArray, queue_size=0)	
	#runs a loop each time values are obtained from the joy topic	
	rospy.Subscriber("joy", Joy, callback)
	rospy.spin()

if __name__ == '__main__':
	try: 
		main()
	except rospy.ROSInterruptException:
		pass
