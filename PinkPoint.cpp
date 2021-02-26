#include "PinkPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

void PinkPoint::update() {
    if(active) {
      CircuitPlayground.setPixelColor(x,100,0,100);
    }
}

PinkPoint::PinkPoint() {

}
