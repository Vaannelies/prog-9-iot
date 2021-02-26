#include "Led.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>



class Enemy: public Led {
  private:
    float X, Y, Z, totalAccel;
  
  public:
    Enemy();
    int x = 0;
    
    void cheat() {
      if(CircuitPlayground.motionX() < -6){
        x = 9;
      }  
    }
    
    void move() {
        x += (rand() %(1 + 1 - (-1))) + (-1);  
        cheat();
    }
    
    void checkX() {
        x == 10 ? x = 0 : false;
        x == -1 ? x = 9 : false;
    }
    
    void update();
};
