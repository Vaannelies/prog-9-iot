#include <Arduino.h>
#include "Point.h"
#include <Adafruit_CircuitPlayground.h>

class PinkPoint: public Point {
  public:
    PinkPoint(int x, boolean active);
    int gx;
    boolean gactive;

    void playSong();

    void collectPoint();
    
    void update();
};
