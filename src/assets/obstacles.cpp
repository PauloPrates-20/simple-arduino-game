#include "obstacles.h"
#include "frame.h"
#include <Arduino.h>

static unsigned long _last_time = 0;

// cacti
uint8_t cacti_large[8] = {0b00100, 0b00101, 0b10101, 0b10101, 0b10111, 0b11100, 0b00100};
uint8_t cacti_small[8] = {0b00000, 0b00000, 0b00100, 0b00101, 0b10111, 0b11100, 0b00100};

// bird
uint8_t bird_down[8] = {0b00000, 0b00100, 0b01100, 0b11110, 0b00111, 0b00110, 0b00100, 0b00000};
uint8_t bird_up[8] = {0b00000, 0b00100, 0b01100, 0b11110, 0b00000, 0b00000, 0b00000};

void animateBird(Obstacle** birds, size_t bird_count) {
  if (millis() - _last_time >= ANIMATION_TIME) {
    for (size_t i = 0; i < bird_count; i++) {
      if (birds[i]->sprite == MEM_OBS_BIRD_UP) birds[i]->sprite = MEM_OBS_BIRD_DOWN;
      else birds[i]->sprite = MEM_OBS_BIRD_UP;
    }

    _last_time = millis();
  }
}