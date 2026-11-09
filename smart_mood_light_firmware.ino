#include <ResponsiveAnalogRead.h>
#include <FastLED.h>

#define NUM_LEDS 60 // Numebr of LEDS
#define DATA_PIN 43 // set to LED DATA

const int ANALOG_PIN = 1; // set to PHOTO DATA



ResponsiveAnalogRead analog(ANALOG_PIN, true);

CRGB leds[NUM_LEDS];

int light_level = 0;
int light_level_to_LED = 0;



void setup() {
  
  Serial.begin(9600);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}



void loop() {

  analog.update();
  light_level = analog.getValue();
  light_level_to_LED = map(light_level, 0, 4095, 255, 0 );

  fill_solid(leds, NUM_LEDS, CRGB::Amber);
  FastLED.setBrightness(light_level_to_LED);

  FastLED.show();

  delay(30);
}