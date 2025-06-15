#pragma once

#include "render.h"

#define MAX_OBSTACLES 8

typedef enum {
  INITIAL,
  GAME,
  END
} screens;

screens initialScreen();
screens gameScreen(Dino* dino, Obstacle* obstacles);
screens endScreen();