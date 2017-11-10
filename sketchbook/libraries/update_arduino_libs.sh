echo "Removing exising roslib: /home/ubuntu/sketchbook/libraries/ros_lib"
rm -rf /home/ubuntu/sketchbook/libraries/ros_lib
rosrun rosserial_arduino make_libraries.py .
