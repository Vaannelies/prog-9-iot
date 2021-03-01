#include <Arduino.h>
#include "Led.h"

class Player: public Led {

  public:
    Player(int x, int lives);
    int gx;
    int glives;

    void checkX();

    void update(int old);
};
