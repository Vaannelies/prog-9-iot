#include <Arduino.h>
#include "Point.h"
#include <Adafruit_CircuitPlayground.h>

class YellowPoint: public Point {
  public:
    YellowPoint(int x, boolean active);
    int gx;
    boolean gactive;
    
    void playSong();
    
    void collectPoint();
    
    void update();


};
