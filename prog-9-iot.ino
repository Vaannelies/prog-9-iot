#include "Enemy.h"
#include "Player.h"
#include "Led.h"
#include "YellowPoint.h"
#include "PinkPoint.h"
#include <string>
#include <Adafruit_CircuitPlayground.h>
int pixels = 10;
boolean showingLives = false;

Enemy e = Enemy(0);
Player p = Player(6,3);
YellowPoint yp = YellowPoint(-1, false);
PinkPoint pp = PinkPoint(-1, false);

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

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
  CircuitPlayground.setPixelColor(p.gx,0,100,0);

  // Turn yellowPoint LED back on
    if(yp.gactive) {
         CircuitPlayground.setPixelColor(yp.gx,100,100,0);
    }


  // Turn pinkPoint LED back on
    if(pp.gactive) {
      CircuitPlayground.setPixelColor(pp.gx,100,0,100);
    }
   
  // check for collision 
  checkPointCollision();
  checkLives(false);
  Serial.println(p.gx == e.gx);
  
  e.update();
  yp.update();
  pp.update();

  // game over if no lives
  if(p.glives <= 0) {
    showingLives = true;
    
    //restart
    p = Player(6,3);
    e = Enemy(0);

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

  if(!yp.gactive) {
    //   spawn yellow point
    int randomMoment = rand() % ((10 - 0) + 1) + 0;
    Serial.println(randomMoment);
    if(randomMoment == 5) {
      yp.gactive = true;
      yp.gx = rand() % ((9 - 0) + 1) + 0;
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
      p.gx--;
      p.update(p.gx+1);
      checkLives(true);  
    };

}

void button_B() {
  // Check button B whenever you want (but not if showingLives is true, so you can't move the player)
    if(showingLives == false) {
      p.gx++;
      p.update(p.gx-1);
      checkLives(true); 
    };
}

void checkLives(boolean player) {
    if(p.gx == e.gx) {
      showingLives = true;
      p.gx = 6;
      e.gx = 0;
      Serial.println(showingLives);
      p.glives--;
      for(int i = 0; i<pixels; i++) {
        CircuitPlayground.setPixelColor(i, 100, 0, 0);
      }

      // Show amount of lives
      switch(p.glives) {        
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
      Serial.print(p.gx);
      Serial.println("enemy  ");
      Serial.print(e.gx);
      showingLives = false;
    }
};

void checkPointCollision() {
  if(p.gx == yp.gx) {
    yp.collectPoint();
  } else if (p.gx == pp.gx) {
    pp.collectPoint();
  }
}
