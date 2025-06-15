#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "render.h"

#define ASSET_N 6

Dino dino = {
  .x = 0,
  .y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

Obstacle bird = {
  .x = 10,
  .sprite = MEM_OBS_BIRD_DOWN,
};

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);
  lcd.begin(16,2);
  lcd.clear();
  loadSprites();
}

void loop() {
  // put your main code here, to run repeatedly:
  animateDino(&dino);
  animateBird(&bird);
  renderGame(&dino, &bird);
}