#!usr/vin/env python
import rospy
import sys
from std_msgs.msg import UInt16

def motor_talker():
	rospy.Publisher('run_motors', UInt16)
	rospy.init_node('motor_talker', anonymous = True)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		ans = int(sys.stdin.readline())
		if (ans > 0 and and < 100):
			rospy.loginfo(ans)
			pub.publish(ans)				
			rate.sleep()
if __name__ == '__main__':
	try:
		spike_talker()
	except rospy.ROSInterruptException:
		pass				
