#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include "display.h"
#include "screens.h"

#define BUTTON_PIN 13

bool button = HIGH;
int32_t score = 0;

Dino dino = {
  .x = 0,
  .y = 1,
  .last_y = 1,
  .state = GROUND,
  .sprite = MEM_DINO_STANDING,
};

Obstacle obstacles[MAX_OBSTACLES] = {
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_SMALL, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_LARGE, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X,  MEM_OBS_BIRD_DOWN, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_BIRD_DOWN, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_SMALL, true},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_CACTI_LARGE, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X,  MEM_OBS_BIRD_DOWN, false},
  {POS_OBS_INITIAL_X, POS_OBS_INITIAL_X, MEM_OBS_BIRD_DOWN, false},
};

LiquidCrystal lcd(RS, ENABLE, D0, D1, D2, D3, D4, D5, D6, D7);

screens currentScreen;

void resetGame();
void startGame();

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(BUTTON_PIN, HIGH);

  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST);

  lcd.begin(16,2);
  lcd.clear();
  loadSprites();
  currentScreen = initialScreen();
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(BUTTON_PIN);

  switch (currentScreen) {
    case INITIAL:
      animateDino(&dino);
      renderGame(&dino, obstacles, MAX_OBSTACLES);
      if (!button) startGame();
      break;
    case GAME:
      currentScreen = gameScreen();
      break;
    case END:
      if (!button) {
        resetGame();
        startGame();
      }
      break;
  }
}

void resetGame() {
  for (size_t i = 0; i < MAX_OBSTACLES; i++ ){
    dino.y = 1;
    obstacles[i].x = POS_OBS_INITIAL_X;
    obstacles[i].last_x = POS_OBS_INITIAL_X;
    obstacles[i].active = false;
    score = 0;
  }
}
void startGame() {
  lcd.clear();
  button = HIGH;
  delay(300);
  currentScreen = gameScreen();
}