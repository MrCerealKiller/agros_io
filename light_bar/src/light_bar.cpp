#include <Arduino.h>
#include <FastLED.h>
#include <ros.h>

#define NUM_LEDS 25
#define SIGNAL_PIN 6

CRGB leds[NUM_LEDS];

uint16_t marker = 0;

void setup() { 
    Serial.begin(115200);
    FastLED.addLeds<WS2812B, SIGNAL_PIN, GRB>(leds, NUM_LEDS);
    LEDS.setBrightness(LED_BRIGHTNESS);
  	LEDS.show();
}

void loop() {
	for (uint16_t i = 0; i < NUM_LEDS; i++) {
    	leds[i] = CRGB::Black;
  	}
    
    leds[marker] = CRGB::Red; 
    FastLED.show();
    marker++; 
    delay(100); 
}