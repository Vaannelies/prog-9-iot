#include <Arduino.h>
#include "Led.h"

class Player: public Led {
  private:

  public:
    Player();
//    int * lives = 3;
//    int * x = 6;
    int lives = 3;
    int x = 6;

    void checkX() {
        // Check if LED is between 0-9
        x == 10 ? x = 0 : false;
        x == -1 ? x = 9 : false;
    }

    void update(int old);
};
