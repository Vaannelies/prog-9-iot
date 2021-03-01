#include "Player.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

void Player::update(int old) {
  checkX();
  
  // Turn off previous LED
  CircuitPlayground.setPixelColor(old, 0,0,0);


  // Turn on the new LED
  CircuitPlayground.setPixelColor(gx,0,100,0);
}

void Player::checkX() {
    // Check if LED is between 0-9
    gx == 10 ? gx = 0 : false;
    gx == -1 ? gx = 9 : false;
}

Player::Player(int x, int lives) {
    gx = x;
    glives = lives;
}
