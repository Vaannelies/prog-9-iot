#include <Arduino.h>
#include "point.h"

class YellowPoint: public Point {
  private:

  public:
    YellowPoint();

    void playSong() {
        // Check if LED is between 0-9
        
    }

    void update();
};
