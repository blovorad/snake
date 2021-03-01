#ifndef __MAP_H__
#define __MAP_H__

#include "core.h"

typedef struct 
{

	SDL_Rect dimension;
	SDL_Color color;

}Tile;

typedef struct 
{

	int width, height;
	Tile **tile;

}Map;

SDL_bool initMap(Map *map);

#endif