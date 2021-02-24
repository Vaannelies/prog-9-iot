#include "Enemy.h"
#include <Adafruit_CircuitPlayground.h>

Enemy e = Enemy();

void setup() {
//   put your setup code here, to run once:
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  e.x += (rand() %(1 + 1 - (-1))) + (-1);
  Serial.println(e.x);
  e.update();
}
