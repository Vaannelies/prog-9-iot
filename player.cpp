#include "player.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void Player::update(int old) {
//  Serial.println("I am a player");
  // Turn of previous LED
  CircuitPlayground.setPixelColor(old, 0,0,0);

  // Check if LED is between 0-9
  x == 10 ? x = 0 : false;
  x == -1 ? x = 9 : false;

  // Turn on the new LED
  CircuitPlayground.setPixelColor(x,0,100,0);
}

Player::Player() {

}
