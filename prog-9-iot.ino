#include "enemy.h"
#include "player.h"
#include "Led.h"
#include <string>
#include <Adafruit_CircuitPlayground.h>
int pixels = 10;
boolean showingLives = false;

Enemy e = Enemy();
Player p = Player();

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
  CircuitPlayground.setPixelColor(p.x,0,100,0);
  
  // check for collision 
  checkLives(false);
  Serial.println(p.x == e.x);
  
  e.update();


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
        CircuitPlayground.setPixelColor(i, 75-(25*p.lives), 0+(25*p.lives), 0);
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
