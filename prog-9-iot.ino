#include "Enemy.h"
#include "Player.h"
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
  
  // Constantly change enemy LED (random)
  e.x += (rand() %(1 + 1 - (-1))) + (-1);


  // Check lightSensor for 'teleporting' enemy back to LED 9 if player is in trouble
  if(analogRead(8) < 20) {
    e.x = 9;
  }
  
  e.update();

  // check for collision 
  checkLives();

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

    delay(2000);
    showingLives = false;
  }
}

void button_A() {
  // Check button A whenever you want (but not if showingLives is true, so you can't move the player)
    if(showingLives == false) {
      p.x--;
      p.update(p.x+1);
      checkLives();  
    }

}

void button_B() {
  // Check button B whenever you want (but not if showingLives is true, so you can't move the player)
    if(showingLives == false) {
      p.x++;
      p.update(p.x-1);
      checkLives(); 
    }

}

void checkLives() {
    if(p.x == e.x) {
      showingLives = true;
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
        
      }
      delay(2000);
      p.x = 6;
      e.x = 0;
      showingLives = false;
    }
}
