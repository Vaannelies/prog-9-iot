#include <Arduino.h>
#include "point.h"
#include <Adafruit_CircuitPlayground.h>

class PinkPoint: public Point {
  private:

  public:
    PinkPoint(int x, boolean active);
    int gx;
    boolean gactive;

    void playSong();

    void collectPoint();
    
    void update();

};
