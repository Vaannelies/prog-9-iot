#include "Led.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>



class Enemy: public Led {
  
  public:
    Enemy(int x);
    int gx;
    
    void cheat();
    
    void move();
    void checkX();
    
    void update();
};
