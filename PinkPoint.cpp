#include "PinkPoint.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

PinkPoint::PinkPoint(int x, boolean active) {
  gx = x;
  gactive = active;
}

void PinkPoint::playSong() {
      Serial.print("lol");
      CircuitPlayground.playTone(1800, 50);
  };
      
void PinkPoint::collectPoint() {
    gactive = false;
    gx = -1;
    playSong();
  };
   

void PinkPoint::update() {
    if(gactive) {
      CircuitPlayground.setPixelColor(gx,100,0,100);
    }
}
