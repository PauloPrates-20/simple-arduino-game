#include "render.h"
#include "frame.h"
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;
static unsigned long _last_render = 0;

void loadSprites() {
  lcd.createChar(MEM_DINO_LEFT_LEG, dino_left_leg);
  lcd.createChar(MEM_DINO_RIGHT_LEG, dino_right_leg);
  lcd.createChar(MEM_DINO_STANDING, dino_standing);
}
void renderGame(const Dino* dino) {
  if (millis() - _last_render >= GAME_TIME) {
    lcd.setCursor(dino->x, dino->y);
    lcd.print(char(dino->sprite));

    _last_render = millis();
  }
}