#include "Enemy.h"
#include <Arduino.h>
#include <Adafruit_CircuitPlayground.h>

  
  void Enemy::update() {
    move();
    checkX();
    CircuitPlayground.setPixelColor(gx,100,0,0);
    delay(300);
  }

  void Enemy::cheat() {
    if(CircuitPlayground.motionX() < -6){
      gx = 9;
    }  
  }
    
  void Enemy::move() {
      gx += (rand() %(1 + 1 - (-1))) + (-1);  
      cheat();
  }

  void Enemy::checkX() {
      gx == 10 ? gx = 0 : false;
      gx == -1 ? gx = 9 : false;
  }

Enemy::Enemy(int x) {
    gx = x;

}
