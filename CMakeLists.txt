cmake_minimum_required(VERSION 3.0.0)
project(agros_io)

find_package(catkin REQUIRED COMPONENTS
  	roscpp
 	rospy
  	rosserial_arduino
  	rosserial_client
  	std_msgs
)

###################################
## Catkin Config ##
###################################

catkin_package(CATKIN_DEPENDS
  	roscpp
 	rospy
  	rosserial_arduino
  	rosserial_client
  	std_msgs
)

###########
## Build ##
###########

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)

rosserial_generate_ros_lib(
  PACKAGE rosserial_arduino
  SCRIPT make_libraries.py
)

rosserial_configure_client(
  DIRECTORY light_bar
  TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(light_bar firmware ALL)
rosserial_add_client_target(light_bar firmware-upload)

#############
## Install ##
#############

# Rosserial will install things automagically
# The watchdog script should not be installed as an executable