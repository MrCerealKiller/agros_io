# Sub Project of AgROS IO
cmake_minimum_required(VERSION 3.0.0)

add_definitions(-DUSB_CON)

generate_arduino_firmware(firmware
  SRCS src/light_bar.cpp
  HDRS ros.h FastLED.h
  BOARD nano328
  PORT /dev/light_bar
)
