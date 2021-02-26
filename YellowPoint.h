#include <Arduino.h>
#include "point.h"
#include <Adafruit_CircuitPlayground.h>

class YellowPoint: public Point {
  private:

  public:
    YellowPoint();
    int x = 0;
    boolean active = false;
    
    void playSong() {
        Serial.print("lol");
//        CircuitPlayground.playTone(800, 100);
    }

    void update();

    void collectPoint() {
      active = false;
      playSong();
    }
};
