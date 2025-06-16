#pragma once

#include "dino.h"
#include "obstacles.h"
#include "stddef.h"

void loadSprites();
void renderGame(Dino* dino, Obstacle* obstacles, size_t obsctacle_count);