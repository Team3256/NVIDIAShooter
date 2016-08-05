NVIDIAShooter:

	ROS Code on Jetson: shooter_ws/src/shooter/scripts/jetson_node.py
	All other scripts are tests and not being used
	Code on Arduino: sketchbook/arduino_node/arduino_node.ino
	All other arduino files are tests and not being used

	To run robot: 
	In Terminal:
		(Each command requires a new terminal to be opened)
		roscore
		rosrun rosserial_python serial_node.py /dev/ttyACM0
		rosrun shooter jetson_node.py
		rosrun joy joy_node
	
