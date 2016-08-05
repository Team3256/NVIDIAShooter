#!/usr/bin/env python
import rospy
import sys
from std_msgs.msg import UInt16
from shooter.msg import driveShootVals

def spike_talker():
	pub = rospy.Publisher('driveShootVals', driveShootVals)
	rospy.init_node('drive_shoot', anonymous = True)
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		vals = driveShootsVals()
		
		shoot_vals = [0][0]
		drive_vals = [0][0]

		vals.shootVals= shoot_vals				
		vals.driveVals= drive_vals
	
		rospy.loginfo(vals)
		pub.publish(vals)				
		rate.sleep()

if __name__ == '__main__':
	try:
		spike_talker()
	except rospy.ROSInterruptException:
		pass				
