# Sub Project of AgROS IO
cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DUSB_CON)

include_directories(
	include
	lib/FastLED 
	${ROS_LIB_DIR}
)

generate_arduino_firmware(firmware
  SRCS lib/FastLED/FastLED.cpp
  	   src/light_bar.cpp
  	   ${ROS_LIB_DIR}/time.cpp
  HDRS lib/FastLED/FastLED.h
  	   include/light_bar.h
  BOARD nano328
  PORT /dev/light_bar
)
