#include "map.h"

SDL_bool initMap(Map *map)
{
	SDL_bool noError = SDL_TRUE;
	map->width = 25;
	map->height = 18;

	map->tile = malloc(sizeof(Tile) * map->height);
	if(map->tile == NULL)
	{
		noError = SDL_FALSE;
	}

	int i = 0;
	while(i < map->width && noError == SDL_TRUE)
	{
		map->tile[i] = malloc(sizeof(Tile) * map->width);
		if(map->tile[i] == NULL)
		{
			noError = SDL_FALSE;
		}
		i++;
	}

	for(int y = 0; y < map->height; y++)
	{
		for(int x = 0; x < map->width; x++)
		{
			SDL_Rect r = {x * 32, y * 32, 32, 32};

			map->tile[y][x].dimension = r;
			map->tile[y][x].color.r = 255;
			map->tile[y][x].color.g = 255;
			map->tile[y][x].color.b = 255;
			map->tile[y][x].color.a = 255;
		}
	}

	return noError;
}