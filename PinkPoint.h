#include <Arduino.h>
#include "point.h"
#include <Adafruit_CircuitPlayground.h>

class PinkPoint: public Point {
  private:

  public:
    PinkPoint();
    int x = -1;
    boolean active = false;

    void playSong() {
        Serial.print("lol");
        CircuitPlayground.playTone(1800, 50);
    }

    void collectPoint() {
      active = false;
      x = -1;
      playSong();
    }
    
    void update();

};
