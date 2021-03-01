#ifndef __INIT_H__
#define __INIT_H__

#include "core.h"
#include "input.h"
#include "map.h"
#include "snake.h"
#include "texture.h"

SDL_bool init(Uint32 flag, SDL_BlendMode blendMode, SDL_Window **window, SDL_Renderer **renderer, Input *input, Map *map, Snake *snake, SDL_Texture *texture[]);

#endif