#include "dino.h"
#include "frame.h"
#include <Arduino.h>

static unsigned long _last_time = 0;

// dino
uint8_t dino_left_leg[8] = {0b00000, 0b00111, 0b00101, 0b00111, 0b10110, 0b11110, 0b01010, 0b01000};
uint8_t dino_right_leg[8] = {0b00000, 0b00111, 0b00101, 0b00111, 0b10110, 0b11110, 0b01010, 0b00010};
uint8_t dino_standing[8] = {0b00000, 0b00111, 0b00101, 0b00111, 0b10110, 0b11110, 0b01010, 0b01010};

void animateDino(Dino* dino) {
  if (dino->state == GROUND) {
    if (millis() - _last_time >= ANIMATION_TIME) {
      if (dino->sprite == MEM_DINO_LEFT_LEG) dino->sprite = MEM_DINO_RIGHT_LEG;
      else dino->sprite = MEM_DINO_LEFT_LEG;

      _last_time = millis();
    }
  }
  else dino->sprite = MEM_DINO_STANDING;
}

void jump(Dino* dino) {
  static uint8_t _jump_frames = 0;
  dino->last_y = dino->y;

  if (dino->state == GROUND) {
    dino->y = 0;
    dino->state = AIR;
    dino->sprite = MEM_DINO_STANDING;
    _jump_frames = 15; 
  }
  else if (_jump_frames > 0) _jump_frames--;
  else {
    dino->y = 1;
    dino->state = GROUND;
  }
}