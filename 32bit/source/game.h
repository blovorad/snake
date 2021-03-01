#ifndef __GAME_H__
#define __GAME_H__

#include "core.h"
#include "init.h"
#include "update.h"
#include "draw.h"
#include "map.h"
#include "snake.h"
#include "texture.h"

void launchGame(void);
void cleanGame(SDL_Window **window, SDL_Renderer **renderer, Map *map, SDL_Texture *texture[]);

#endif