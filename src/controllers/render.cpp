#include "render.h"
#include "frame.h"
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
static unsigned long _last_render = 0;

void loadSprites() {
  lcd.createChar(MEM_DINO_LEFT_LEG, dino_left_leg);
  lcd.createChar(MEM_DINO_RIGHT_LEG, dino_right_leg);
  lcd.createChar(MEM_DINO_STANDING, dino_standing);
  lcd.createChar(MEM_OBS_CACTI_LARGE, cacti_large);
  lcd.createChar(MEM_OBS_CACTI_SMALL, cacti_small);
  lcd.createChar(MEM_OBS_BIRD_DOWN, bird_down);
  lcd.createChar(MEM_OBS_BIRD_UP, bird_up);
}
void renderGame(const Dino* dino, const Obstacle* obstacle) {
  if (millis() - _last_render >= GAME_TIME) {
    lcd.setCursor(dino->x, dino->y);
    lcd.print(char(dino->sprite));
    lcd.setCursor(obstacle->x, 1);
    lcd.print(char(obstacle->sprite));

    _last_render = millis();
  }
}