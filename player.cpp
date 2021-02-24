#include "player.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void Player::update() {
  Serial.println("I am a player");
//  CircuitPlayground.clearPixels();
  x == 10 ? x = 0 : false;
  x == -1 ? x = 9 : false;
  CircuitPlayground.setPixelColor(x,0,255,0);
  delay(300);
}

Player::Player() {

}
