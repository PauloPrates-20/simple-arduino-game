#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "render.h"

#define ASSET_N 6
#define MAX_OBSTACLES 4

Dino dino = {
  .x = 0,
  .y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

Obstacle obstacles[MAX_OBSTACLES] = {
  {25, 25, MEM_OBS_CACTI_SMALL, true},
  {20, 20, MEM_OBS_CACTI_LARGE, true},
  {15, 15,  MEM_OBS_BIRD_DOWN, true},
  {27, 27, MEM_OBS_BIRD_DOWN, true},
};

Obstacle* birds[2] = {&obstacles[2], &obstacles[3]};

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
  animateBird(birds, 2);
  moveObstacles(obstacles, MAX_OBSTACLES);
  renderGame(&dino, obstacles, MAX_OBSTACLES);
}