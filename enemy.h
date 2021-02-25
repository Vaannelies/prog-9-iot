#include "Led.h"
#include <Arduino.h>

class Enemy: public Led {
  private:
  
  public:
    Enemy();
    int x = 0;
    void cheat() {
      // Check lightSensor for 'teleporting' enemy back to LED 9 if player is in trouble
      Serial.print("analogread: ");
      Serial.println(analogRead(8));
      if(analogRead(8) < 50) {
        x = 9;
      }
    }
    
    void move() {
        x += (rand() %(1 + 1 - (-1))) + (-1);  
    }
    
    void checkX() {
        x == 10 ? x = 0 : false;
        x == -1 ? x = 9 : false;
    }
    
    void update();
};
