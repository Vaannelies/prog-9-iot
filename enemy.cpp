#include "enemy.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

#define LED

void Enemy::update() {;
  x == 10 ? x = 0 : false;
  x == -1 ? x = 9 : false;
  CircuitPlayground.setPixelColor(x,100,0,0);
  delay(300);
}

Enemy::Enemy() {

}
