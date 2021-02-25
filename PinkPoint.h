#include <Arduino.h>
#include "point.h"

class PinkPoint: public Point {
  private:

  public:
    PinkPoint();
    int lives = 3;
    int x = 6;

    void checkX() {
        // Check if LED is between 0-9
        x == 10 ? x = 0 : false;
        x == -1 ? x = 9 : false;
    }

    void update(int old);
};
