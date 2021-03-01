#include "init.h"

SDL_bool init(Uint32 flag, SDL_BlendMode blendMode, SDL_Window **window, SDL_Renderer **renderer, Input *input, Map *map, Snake *snake, SDL_Texture *texture[])
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

	if(IMG_Init(IMG_INIT_PNG) == 0)
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
	if(!initTexture(*renderer, texture))
	{
		return SDL_FALSE;
	}
	initSnake(snake);
	initInput(input);

	return SDL_TRUE;
}