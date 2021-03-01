#include "YellowPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

YellowPoint::YellowPoint(int x, boolean active) {
    gx = x;
    gactive = active;
}

void YellowPoint::playSong(){
        CircuitPlayground.playTone(800, 50);
}

void YellowPoint::collectPoint() {
      gactive = false;
      gx = -1;
      playSong();
}

void YellowPoint::update() {
  if(gactive) {
    CircuitPlayground.setPixelColor(gx,100,100,0);
  }
}
