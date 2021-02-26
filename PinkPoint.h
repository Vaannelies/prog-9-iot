#include <Arduino.h>
#include "point.h"

class PinkPoint: public Point {
  private:

  public:
    PinkPoint();
    int x = 0;
    boolean active = false;

    void playSong() {
        Serial.print("lol");
//        CircuitPlayground.playTone(800, 100);
    }

    void collectPoint() {
      active = false;
      playSong();
    }
    
    void update();

};
