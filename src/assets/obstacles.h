#pragma once

#include <stdint.h>
#include <stddef.h>

// obstacle sprites locations in LCD display memory
#define MEM_OBS_CACTI_LARGE 3
#define MEM_OBS_CACTI_SMALL 4
#define MEM_OBS_BIRD_DOWN 5
#define MEM_OBS_BIRD_UP 6

// obstacle initial positions
#define POS_OBS_INITIAL_X 20

// cacti
extern uint8_t cacti_large[8];
extern uint8_t cacti_small[8];

// bird
extern uint8_t bird_down[8];
extern uint8_t bird_up[8];

typedef struct {
  int8_t x;
  int8_t last_x;
  uint8_t sprite;
  bool active;
} Obstacle;

void animateBird(Obstacle** birds, size_t bird_count);
void moveObstacles(Obstacle* obstacles, size_t obstacle_count);