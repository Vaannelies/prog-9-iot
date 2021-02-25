#include "YellowPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED
int r = rand() %0 + 9;
void YellowPoint::update() {
  playSong();
  CircuitPlayground.setPixelColor(r,100,0,100);
}

YellowPoint::YellowPoint() {

}
