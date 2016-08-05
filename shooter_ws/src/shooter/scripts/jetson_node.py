#!/usr/bin/env python
import rospy

from std_msgs.msg import Float32
from sensor_msgs.msg import Joy
from std_msgs.msg import Bool
def callback(data):
	ldrive=float(50*data.axes[1])
	rdrive=float(50*data.axes[4])
	LDPub.publish(ldrive);
	RDPub.publish(rdrive);
	lbarrel = data.buttons[2]
	rbarrel = data.buttons[1]
	LBPub.publish(lbarrel)
	RBPub.publish(rbarrel)
def motor_talker():
	rospy.init_node('node');
	global LDPub
	LDPub = rospy.Publisher('l_motor', Float32, queue_size=0)	
	global RDPub
	RDPub = rospy.Publisher('r_motor', Float32, queue_size=0)
	global LBPub
	LBPub = rospy.Publisher('l_barrel', Bool, queue_size=0)
	global RBPub
	RBPub = rospy.Publisher('r_barrel', Bool, queue_size=0)
	rospy.Subscriber("joy", Joy, callback)
	rospy.spin()
	
if __name__ == '__main__':
	try: 
		motor_talker()
	except rospy.ROSInterruptException:
		pass
