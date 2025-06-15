#pragma once

#include <stdint.h>
#include <stddef.h>

#define MEM_OBS_CACTI_LARGE 3
#define MEM_OBS_CACTI_SMALL 4
#define MEM_OBS_BIRD_DOWN 5
#define MEM_OBS_BIRD_UP 6

// cacti
extern uint8_t cacti_large[8];
extern uint8_t cacti_small[8];

// bird
extern uint8_t bird_down[8];
extern uint8_t bird_up[8];

typedef struct {
  uint8_t x;
  uint8_t sprite;
} Obstacle;

void animateBird(Obstacle** birds, size_t bird_count);