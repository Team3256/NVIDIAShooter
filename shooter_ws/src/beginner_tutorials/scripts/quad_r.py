#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32
def callback(data):
	rospy.loginfo("The solution(s) is/are %s", data.data)

def listener():
	rospy.init_node('quad_r', anonymous=True)
	rospy.Subscriber("quadratic", Int32, callback)
	rospy.spin()

if __name__ == '__main__':
	listener()

