#include "obstacles.h"
#include "frame.h"
#include <Arduino.h>

static unsigned long _last_sprite = 0;
static unsigned long _last_move = 0;

// cacti
uint8_t cacti_large[8] = {0b00100, 0b00101, 0b10101, 0b10101, 0b10111, 0b11100, 0b00100};
uint8_t cacti_small[8] = {0b00000, 0b00000, 0b00100, 0b00101, 0b10111, 0b11100, 0b00100};

// bird
uint8_t bird_down[8] = {0b00000, 0b00100, 0b01100, 0b11110, 0b00111, 0b00110, 0b00100, 0b00000};
uint8_t bird_up[8] = {0b00000, 0b00100, 0b01100, 0b11110, 0b00000, 0b00000, 0b00000};

void animateBird(Obstacle** birds, size_t bird_count) {
  if (millis() - _last_sprite >= ANIMATION_TIME) {
    for (size_t i = 0; i < bird_count; i++) {
      if (birds[i]->sprite == MEM_OBS_BIRD_UP) birds[i]->sprite = MEM_OBS_BIRD_DOWN;
      else birds[i]->sprite = MEM_OBS_BIRD_UP;
    }

    _last_sprite = millis();
  }
}

void moveObstacles(Obstacle* obstacles, size_t obstacle_count) {
  if (millis() - _last_move >= GAME_TIME * 7) {
    for (size_t i = 0; i < obstacle_count; i++) {
      if (obstacles[i].active) {
        obstacles[i].last_x = obstacles[i].x;
        obstacles[i].x -= 1;
      }

      if (obstacles[i].x < 0) {
        obstacles[i].active = false;
        obstacles[i].x = POS_OBS_INITIAL_X;
        obstacles[i].last_x = POS_OBS_INITIAL_X;
      }
    }

    _last_move = millis();
  }
}