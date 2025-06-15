#include "screens.h"
#include <LiquidCrystal.h>
#include "dino.h"
#include "obstacles.h"

extern LiquidCrystal lcd;
extern Obstacle obstacles[MAX_OBSTACLES];
Obstacle* birds[2] = { &obstacles[2], &obstacles[3] };

const char* _title = "ARDUDINO UNO";

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
    delay(300);    
  }

  return INITIAL;
}

screens gameScreen(Dino* dino, Obstacle* obstacles) {
  animateDino(dino);
  animateBird(birds, 2);
  randomObstacleSpawn(obstacles, MAX_OBSTACLES);
  moveObstacles(obstacles, MAX_OBSTACLES);
  renderGame(dino, obstacles, MAX_OBSTACLES);

  return GAME;
}

screens endScreen() {

}