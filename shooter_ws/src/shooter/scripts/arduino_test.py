#!/usr/bin/env python
import rospy
import sys
from std_msgs.msg import UInt16

def arduino_talker():
	pub = rospy.Publisher("test", UInt16)
	rospy.init_node('arduino_talker', anonymous=True)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		ans = int(sys.stdin.readline())
		if (ans):
			rospy.loginfo(ans)
			pub.publish(ans)
			rate.sleep()
if __name__ == '__main__':
	try:
		arduino_talker()
	except rospy.ROSInterruptException:
		pass	
