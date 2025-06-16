#pragma once

#include <stdint.h>

// sprite position in LCD display memory
#define MEM_DINO_LEFT_LEG 0
#define MEM_DINO_RIGHT_LEG 1
#define MEM_DINO_STANDING 2

// dino sprete positions
#define POS_DINO_X 0
#define POS_DINO_GROUND_Y 1
#define POS_DINO_AIR_Y 0

// dino
// sprites
extern uint8_t dino_left_leg[8];
extern uint8_t dino_right_leg[8];
extern uint8_t dino_standing[8];

// states
// movement
typedef enum {
  GROUND,
  MID,
  AIR,
} dino_state;

// dino object
typedef struct {
  uint8_t x;
  uint8_t y;
  dino_state state;
  uint8_t sprite;
} Dino;

void animateDino(Dino* dino);
void jump(Dino* dino);