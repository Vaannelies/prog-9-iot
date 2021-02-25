#include "Led.h"

class Enemy: public Led {
  private:
  
  public:
    Enemy();
    int x = 0;
    void checkX() {
        x == 10 ? x = 0 : false;
        x == -1 ? x = 9 : false;
    }
    
    void update();
};
