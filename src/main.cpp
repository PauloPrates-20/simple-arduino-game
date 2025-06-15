#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "render.h"

#define ASSET_N 6
#define MAX_OBSTACLES 3

Dino dino = {
  .x = 0,
  .y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

Obstacle obstacles[MAX_OBSTACLES] = {
  {10, MEM_OBS_CACTI_SMALL},
  {15, MEM_OBS_CACTI_LARGE},
  {5, MEM_OBS_BIRD_DOWN},
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
  animateBird(&obstacles[2]);
  renderGame(&dino, obstacles, MAX_OBSTACLES);
}