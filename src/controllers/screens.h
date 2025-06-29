#pragma once

#include "render.h"

#define MAX_OBSTACLES 8

typedef enum {
  INITIAL,
  GAME,
  END
} screens;

screens initialScreen();
screens gameScreen();
screens endScreen();
void clearLine(uint8_t y);