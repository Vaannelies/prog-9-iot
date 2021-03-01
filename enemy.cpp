#include "enemy.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

  
void Enemy::update() {
  
  move();
  checkX();
  CircuitPlayground.setPixelColor(x,100,0,0);
  delay(300);
}

Enemy::Enemy() {

}
