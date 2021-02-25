#include "enemy.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void Enemy::update() {
  
  move();
  checkX();
  CircuitPlayground.setPixelColor(x,100,0,0);
  cheat();
  delay(300);
}

Enemy::Enemy() {

}
