#include "YellowPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void YellowPoint::update(int old) {
  checkX();
  
  // Turn of previous LED
  CircuitPlayground.setPixelColor(old, 0,0,0);


  // Turn on the new LED
  CircuitPlayground.setPixelColor(x,0,100,0);
}

YellowPoint::YellowPoint() {

}
