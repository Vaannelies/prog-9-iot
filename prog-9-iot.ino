#include "Enemy.h"
#include "Player.h"
#include <Adafruit_CircuitPlayground.h>

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
  Serial.println(analogRead(8));
  if(analogRead(8) < 20) {
    e.x = 9;
  }
  
  e.update();
}

void button_A() {
  // Check button A whenever you want
    p.x++;
    p.update(p.x-1);
}

void button_B() {
  // Check button B whenever you want
    p.x--;
    p.update(p.x+1);
}
