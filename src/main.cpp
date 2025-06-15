#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "render.h"
#include "dino.h"
#include "obstacles.h"

#define ASSET_N 6

Dino dino = {
  .x = 0,
  .y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);
  lcd.begin(16,2);
  lcd.clear();
  loadSprites();
  lcd.createChar(3, cacti_large);
  lcd.createChar(4, cacti_small);
  lcd.createChar(5, bird);
}

void loop() {
  // put your main code here, to run repeatedly:
  animateDino(&dino);
  renderGame(&dino);
}