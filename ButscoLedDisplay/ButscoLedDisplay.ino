#include <FastLED.h>
#include <LEDMatrix.h>
#include <TextScroller.h>
#include <FontMatrise.h>

#define STRIPS_ROWS         8   
#define NUM_LEDS_PER_STRIP  121

// create a ledmatrix 
cLEDMatrix<NUM_LEDS_PER_STRIP, STRIPS_ROWS, HORIZONTAL_MATRIX> leds;

// create a textscroller object
cTextScroller ScrollingMsg;

/*************************
 *  THE TEXT TO DISPLAY  *
 *************************/
const unsigned char TxtDemo[] = { 
  EFFECT_FRAME_RATE "\x01"
  EFFECT_HSV_AH "\x00\xff\xff\x40\xff\xfff"
  EFFECT_SCROLL_LEFT "                     UNLEASHED THE BEAST"
};

void setup()
{
  // tell FastLED about the LED strip configuration  
  FastLED.addLeds<WS2812B, 2, GRB>(leds[0], 0                     , NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 3, GRB>(leds[0], 1 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 4, GRB>(leds[0], 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 5, GRB>(leds[0], 3 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 6, GRB>(leds[0], 4 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 7, GRB>(leds[0], 5 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 8, GRB>(leds[0], 6 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, 9, GRB>(leds[0], 7 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP).setCorrection(TypicalLEDStrip);
  
  // set master brightness control
  FastLED.setBrightness(50);
  
  FastLED.clear(true);
  
  ScrollingMsg.SetFont(MATRISE_WIDTH, MATRISE_HEIGHT, MATRISE_CHAR_LOW, MATRISE_CHAR_HIGH, MatriseData);
  ScrollingMsg.Init(&leds, NUM_LEDS_PER_STRIP, STRIPS_ROWS, 0, 1);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0xff, 0xff);
}


void loop()
{
  if (ScrollingMsg.UpdateText() == -1)
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  else
    FastLED.show();
  delay(10);
}
