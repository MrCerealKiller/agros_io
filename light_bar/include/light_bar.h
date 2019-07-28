#ifndef _LIGHT_BAR_H
#define _LIGHT_BAR_H

#include <Arduino.h>
#include <FastLED.h>
#include <ros.h>
#include <std_msgs/Float64.h>

#define NUM_LEDS 25
#define SIGNAL_PIN 6

#define BEARING_TOPIC "/path/tarAngle"

#ifndef PI
#define PI 3.14159265359
#endif

#define WARNING_THRESH 15
#define DANGER_THRESH 25

void bearingCb(const std_msgs::Float64& msg);
void setup();
void loop();

#endif //_LIGHT_BAR_H