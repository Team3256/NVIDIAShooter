#!/usr/bin/env python
import rospy
import sys
import math
from std_msgs.msg import Int32

def solve(a, b, c):
	discrim = (int(b)*int(b)-4*int(a)*int(c))
	if (discrim < 0):
		return 0
	elif (discrim == 0):
		return (-int(b)/(2*int(a)))
	else: 
		return (int((-int(b)+math.sqrt(discrim))/(2*int(a))),int((-int(b)-math.sqrt(discrim))/(2*int(a))))

def quad_t():
	rospy.init_node('quad_t',anonymous=True)
	pub=rospy.Publisher('quadratic', Int32, queue_size = 10)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		a = sys.stdin.readline()
		b = sys.stdin.readline()
		c = sys.stdin.readline()
		if (a and b and c):
			ans = solve(a,b,c)
			rospy.loginfo(ans)
			pub.publish(ans)
			rate.sleep()

if __name__ == '__main__':
	try:
		quad_t()
	except	rospy.ROSInterruptException:
		pass

