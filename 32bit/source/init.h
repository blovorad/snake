#ifndef __INIT_H__
#define __INIT_H__

#include "core.h"
#include "input.h"
#include "map.h"

SDL_bool init(Uint32 flag, SDL_BlendMode blendMode, SDL_Window **window, SDL_Renderer **renderer, Input *input, Map *map);

#endif