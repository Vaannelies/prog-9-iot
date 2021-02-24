#include "Enemy.h"
#include "Player.h"
#include <Adafruit_CircuitPlayground.h>

Enemy e = Enemy();
Player p = Player();

void setup() {
//   put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Change enemy LED (random)
  e.x += (rand() %(1 + 1 - (-1))) + (-1);
  e.update();

  // Check button for player
  if(CircuitPlayground.leftButton() == true) {
    Serial.println("left");
    p.x++;
  } else if(CircuitPlayground.rightButton() == true) {
    p.x--;
  }
  p.update();
  
}
