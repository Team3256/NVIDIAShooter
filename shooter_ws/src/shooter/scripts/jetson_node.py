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

def callback(data):
	global old_lreload
	global old_rreload
	array = Float32MultiArray()
	ldrive,rdrive = arcadeDrive(float(data.axes[1]),float(-data.axes[2]))
	pivotSpeed = .2
	#trigger ports 8 and 9
	lshoot = int(data.buttons[10])
	rshoot = int(data.buttons[11])
	lreload = int(data.buttons[15])
	lreload = lreload and not old_lreload
	rreload = int(data.buttons[13])
	rreload = rreload and not old_rreload
	pivotForward = int(data.buttons[12])
	pivotBackward = int(data.buttons[14])	

	curr_time = get_time()
	array.data = [ldrive,rdrive,pivotSpeed,lshoot,rshoot,lreload,rreload,pivotForward,pivotBackward,curr_time]
	controls_pub.publish(array)	
	old_lreload = lreload
	old_rreload = rreload

def main():
	rospy.init_node('ShooterNode')
	global initial_time
	initial_time = datetime.now()
	global controls_pub
	controls_pub = rospy.Publisher('controls', Float32MultiArray, queue_size=0)
	
	rospy.Subscriber("joy", Joy, callback)
	rospy.spin()

if __name__ == '__main__':
	try: 
		main()
	except rospy.ROSInterruptException:
		pass
