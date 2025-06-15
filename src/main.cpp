#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "screens.h"

Dino dino = {
  .x = 0,
  .y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

Obstacle obstacles[MAX_OBSTACLES] = {
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_SMALL, true},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_LARGE, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X,  MEM_OBS_BIRD_DOWN, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_BIRD_DOWN, false},
};

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);

screens currentScreen;

void setup() {
  // put your setup code here, to run once:
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);
  lcd.begin(16,2);
  lcd.clear();
  loadSprites();
  currentScreen = initialScreen();
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentScreen = gameScreen(&dino, obstacles);
}