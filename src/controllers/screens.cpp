#include "screens.h"
#include <LiquidCrystal.h>
#include "dino.h"
#include "obstacles.h"

extern LiquidCrystal lcd;
extern uint32_t score;
extern Dino dino;
extern Obstacle obstacles[MAX_OBSTACLES];
Obstacle* birds[MAX_OBSTACLES / 2] = { &obstacles[2], &obstacles[3], &obstacles[6], &obstacles[7] };

const char* _title = "ARDUDINO UNO";
const char* _ending = "GAME OVER!!!";

screens initialScreen() {
  lcd.setCursor(POS_DINO_X, POS_DINO_GROUND_Y);
  lcd.print(char(MEM_DINO_STANDING));
  lcd.setCursor(POS_DINO_X + 5, POS_DINO_GROUND_Y);
  lcd.print(char(MEM_OBS_CACTI_SMALL));
  lcd.setCursor(POS_DINO_X + 10, POS_DINO_GROUND_Y);
  lcd.print(char(MEM_OBS_CACTI_LARGE));
  lcd.setCursor(POS_DINO_X + 15, POS_DINO_GROUND_Y);
  lcd.print(char(MEM_OBS_CACTI_SMALL));

  for (size_t i = 0; i < strlen(_title); i++) {
    lcd.setCursor(((16 - strlen(_title)) / 2) + i, 0);
    lcd.print(_title[i]);
    delay(200);    
  }

  return INITIAL;
}

screens gameScreen() {
  animateDino(&dino);
  animateBird(birds, MAX_OBSTACLES / 2);
  randomObstacleSpawn(obstacles, MAX_OBSTACLES);
  moveObstacles(obstacles, MAX_OBSTACLES);

  for (size_t i = 0; i < MAX_OBSTACLES; i++) if (checkCollision(&dino, obstacles[i].x)) return endScreen();

  renderGame(&dino, obstacles, MAX_OBSTACLES, true);

  return GAME;
}

screens endScreen() {
  char _score[17];

  clearLine(0);

  for (size_t i = 0; i < strlen(_ending); i++) {
    lcd.setCursor(((16 - strlen(_ending)) / 2) + i, 0);
    lcd.print(_ending[i]);
    delay(200);
  }

  delay(1000);

  sprintf(_score, "SCORE: %lu", score);
  clearLine(0);
  for (size_t i = 0; i < strlen(_score); i++) {
    lcd.setCursor(3 + i, 0);
    lcd.print(_score[i]);
    delay(200);
  }

  return END;
}

void clearLine(uint8_t y) {
  lcd.setCursor(1, y);
  lcd.print("              ");
}