#include "init.h"

SDL_bool init(Uint32 flag, SDL_BlendMode blendMode, SDL_Window **window, SDL_Renderer **renderer, Input *input, Map *map)
{
	if(SDL_Init(flag) < 0)
	{
		return SDL_FALSE;
	}

	*window = SDL_CreateWindow("SNAKE BY BLOVORAD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if(*window == NULL)
	{
		return SDL_FALSE;
	}

	*renderer = SDL_CreateRenderer(*window, -1, 1);
	if(*renderer == NULL)
	{
		return SDL_FALSE;
	}

	if(SDL_SetRenderDrawBlendMode(*renderer, blendMode) < 0)
	{
		return SDL_FALSE;
	}

	if(!initMap(map))
	{
		return SDL_FALSE;
	}

	initInput(input);

	return SDL_TRUE;
}