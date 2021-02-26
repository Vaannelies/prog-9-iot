#include "YellowPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

void YellowPoint::update() {
  if(active) {
    CircuitPlayground.setPixelColor(x,100,100,0);
  }
}

YellowPoint::YellowPoint() {

}
