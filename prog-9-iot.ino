#include "enemy.h"
#include "player.h"
#include "Led.h"
#include "YellowPoint.h"
#include "PinkPoint.h"
#include <string>
#include <Adafruit_CircuitPlayground.h>
int pixels = 10;
boolean showingLives = false;

Enemy e = Enemy();
Player p = Player();
YellowPoint yp = YellowPoint();
PinkPoint pp = PinkPoint(-1, false);

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);
  
  attachInterrupt(
    digitalPinToInterrupt(4),
    button_A,
    RISING
  );
  attachInterrupt(
    digitalPinToInterrupt(5),
    button_B,
    RISING
  );
}

void loop() {
  // Turn off all LEDs
  CircuitPlayground.clearPixels();

  // Turn player LED back on
  CircuitPlayground.setPixelColor(p.x,0,100,0);

  // Turn yellowPoint LED back on
    if(yp.active) {
         CircuitPlayground.setPixelColor(yp.x,100,100,0);
    }


  // Turn pinkPoint LED back on
    if(pp.gactive) {
      CircuitPlayground.setPixelColor(pp.gx,100,0,100);
    }
   
  // check for collision 
  checkPointCollision();
  checkLives(false);
  Serial.println(p.x == e.x);
  
  e.update();
  yp.update();
  pp.update();

  // game over if no lives
  if(p.lives <= 0) {
    showingLives = true;
    
    //restart
    p = Player();
    e = Enemy();

    // show that player has 3 lives
    CircuitPlayground.setPixelColor(0, 0,0,100);
    CircuitPlayground.setPixelColor(1, 0,0,100);

    CircuitPlayground.setPixelColor(4, 0,0,100);
    CircuitPlayground.setPixelColor(5, 0,0,100);

    CircuitPlayground.setPixelColor(8, 0,0,100);
    CircuitPlayground.setPixelColor(9, 0,0,100);

    delay(1000);
    showingLives = false;
  }

  if(!yp.active) {
    //   spawn yellow point
    int randomMoment = rand() % ((10 - 0) + 1) + 0;
    Serial.println(randomMoment);
    if(randomMoment == 5) {
      yp.active = true;
      yp.x = rand() % ((9 - 0) + 1) + 0;
    }
  }

    if(!pp.gactive) {
    //   spawn pink point
    int randomMoment = rand() % ((50 - 0) + 1) + 0;
    Serial.println(randomMoment);
    if(randomMoment == 5) {
      pp.gactive = true;
      pp.gx = rand() % ((9 - 0) + 1) + 0;
    }
  }

}

void button_A() {
  // Check button A whenever you want (but not if showingLives is true, so you can't move the player)
    if(showingLives == false) {
      p.x--;
      p.update(p.x+1);
      checkLives(true);  
    };

}

void button_B() {
  // Check button B whenever you want (but not if showingLives is true, so you can't move the player)
    if(showingLives == false) {
      p.x++;
      p.update(p.x-1);
      checkLives(true); 
    };
}

void checkLives(boolean player) {
    if(p.x == e.x) {
      showingLives = true;
      p.x = 6;
      e.x = 0;
      Serial.println(showingLives);
      p.lives--;
      for(int i = 0; i<pixels; i++) {
        CircuitPlayground.setPixelColor(i, 100, 0, 0);
      }

      // Show amount of lives
      switch(p.lives) {        
        case 2 :
          CircuitPlayground.setPixelColor(0, 0,0,100);
          CircuitPlayground.setPixelColor(1, 0,0,100);
    
          CircuitPlayground.setPixelColor(4, 0,0,100);
          CircuitPlayground.setPixelColor(5, 0,0,100);
          break;

        case 1 :
          CircuitPlayground.setPixelColor(0, 0,0,100);
          CircuitPlayground.setPixelColor(1, 0,0,100);
          break;

        case 0 :
          for(int i = 0; i<pixels; i++) {
            CircuitPlayground.setPixelColor(i, 100, 0, 0);
          }
          break;        
      }
      
      if(player == true) {
        delay(1000000);
      } else {
        delay(3000);
      };
      Serial.println("player  ");
      Serial.print(p.x);
      Serial.println("enemy  ");
      Serial.print(e.x);
      showingLives = false;
    }
};

void checkPointCollision() {
  if(p.x == yp.x) {
    yp.collectPoint();
  } else if (p.x == pp.gx) {
    pp.collectPoint();
  }
}
