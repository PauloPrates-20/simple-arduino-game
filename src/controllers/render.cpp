#include "render.h"
#include "frame.h"
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
extern bool button;
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

void renderGame(Dino* dino, const Obstacle* obstacles, size_t obstacle_count) {
  if (millis() - _last_render >= GAME_TIME) {
    if (!button || dino->state != GROUND) {
      jump(dino);
    }

    if (dino->last_y != dino->y) {
      lcd.setCursor(dino->x, dino->last_y);
      lcd.print(" ");
    }

    lcd.setCursor(dino->x, dino->y);
    lcd.print(char(dino->sprite));

    for (size_t i = 0; i < obstacle_count; i++) {
      if (obstacles[i].active) {
        lcd.setCursor(obstacles[i].last_x, 1);
        lcd.print(" ");
        lcd.setCursor(obstacles[i].x, 1);
        lcd.print(char(obstacles[i].sprite));
      }
    }

    _last_render = millis();
  }
}