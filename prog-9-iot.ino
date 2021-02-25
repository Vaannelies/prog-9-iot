#include "Enemy.h"
#include "Player.h"
#include <Adafruit_CircuitPlayground.h>
int pixels = 9;

Enemy e = Enemy();
Player p = Player();

void setup() {
//   put your setup code here, to run once:
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

  // Game
  // check for collision 
  checkLives();
//  Serial.println("=========================");
  
//  Serial.println("=========================");


  // game over if no lives
  if(p.lives <= 0) {
    Serial.println(p.lives);
    //restart
    for(int i = 0; i<pixels; i++) {
      CircuitPlayground.setPixelColor(i, 75*p.lives,75*p.lives,75*p.lives);
    }
    delay(2000);
    p = Player();
    e = Enemy();
  }
}

void button_A() {
  // Check button A whenever you want
    p.x--;
    p.update(p.x+1);
    checkLives();
}

void button_B() {
  // Check button B whenever you want
    p.x++;
    p.update(p.x-1);
    checkLives();
}

void checkLives() {
    if(p.x == e.x) {
      p.lives--;
      for(int i = 0; i<pixels; i++) {
        CircuitPlayground.setPixelColor(i, 75-25*p.lives, 0+25*p.lives, 0);
      }
      delay(2000);
    }
}
