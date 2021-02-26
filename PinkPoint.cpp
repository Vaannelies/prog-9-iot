#include "PinkPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void PinkPoint::update() {
    CircuitPlayground.setPixelColor(x,100,0,100);
}

PinkPoint::PinkPoint() {

}
