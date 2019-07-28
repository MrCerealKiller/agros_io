#include "light_bar.h"

ros::NodeHandle nh;
CRGB leds[NUM_LEDS];

ros::Subscriber<std_msgs::Float64> sub(BEARING_TOPIC, &bearingCb);

void setup()
{
    FastLED.addLeds<WS2812B, SIGNAL_PIN, GRB>(leds, NUM_LEDS);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB::Purple;
    }

    nh.initNode();
    nh.subscribe(sub);

    FastLED.setBrightness(60);
  	FastLED.show();
}

void loop()
{
    nh.spinOnce();
    delay(1);
}

void bearingCb(const std_msgs::Float64& msg)
{
    // Clear the LEDs
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CRGB::Black;
    }

    // Convert from RAD to DEG and constrain to 90deg
    double bearing = ((double)msg.data / PI) * 180;
    double bearingCon = constrain(bearing, -45, 45);

    // Check the bucket the bearing is in (i.e. the light)
    int bucket = map(bearingCon, -45, 45, 0, 22);

    // Check threshold
    if (abs(bearing) < WARNING_THRESH)
    {
        leds[0] = CRGB::Green;
        leds[(NUM_LEDS - 1)] = CRGB::Green;
        leds[(bucket + 1)] = CRGB::Green;
    }
    else if (abs(bearing) > DANGER_THRESH)
    {
        leds[0] = CRGB::Red;
        leds[(NUM_LEDS - 1)] = CRGB::Red;
        leds[(bucket + 1)] = CRGB::Red;
    }
    else
    {
        leds[0] = CRGB::Orange;
        leds[(NUM_LEDS - 1)] = CRGB::Orange;
        leds[(bucket + 1)] = CRGB::Orange;
    }

    FastLED.show();
}