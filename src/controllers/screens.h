#pragma once

#include "render.h"

#define MAX_OBSTACLES 4

typedef enum {
  INITIAL,
  GAME,
  END
} screens;

screens initialScreen();
screens gameScreen();
screens endScreen();