#!/usr/bin/env python
import rospy
import math

from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Joy

def arcadeDrive(throttle,turn):
	left = throttle + turn
	right = throttle - turn
	left = 1 if left > 1 else left
	left = -1 if left < -1 else left
	right = 1 if right > 1 else right
	right = -1 if right < -1 else right	
	if math.fabs(left) < 0.25:
		left = 0
	if math.fabs(right) < 0.25:
		right = 0
	left = left*0.5
	right = right*0.5
	return left,right

old_lshoot = False
old_rshoot = False

def callback(data):
	global old_lreload
	global old_rreload

	array = Float32MultiArray()

	ldrive,rdrive = arcadeDrive(float(data.axes[1]),float(-data.axes[2]))

	global old_lshoot
	global old_rshoot
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

	array.data = [ldrive,rdrive,lshoot,rshoot,lreload,rreload,pivotForward,pivotBackward, lbumper, rbumper]
	controls_pub.publish(array)	
	
	old_lreload = lreload
	old_rreload = rreload
	old_lshoot = lshoot	
	old_rshoot = rshoot

def main():
	rospy.init_node('ShooterNode')
	global controls_pub
	controls_pub = rospy.Publisher('controls', Float32MultiArray, queue_size=0)
	
		
	rospy.Subscriber("joy", Joy, callback)
	rospy.spin()

if __name__ == '__main__':
	try: 
		main()
	except rospy.ROSInterruptException:
		pass
