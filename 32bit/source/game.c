#include "game.h"


void launchGame(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	Uint32 flag = SDL_INIT_EVERYTHING;
	SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND;
	Input input;
	Map map;
	map.width = 0;

	SDL_bool go = init(flag, blendMode, &window, &renderer, &input, &map);

	while(go)
	{
		go = update(&input);
		if(go)
		{
			go = draw(renderer, map);
		}
	}

	cleanGame(&window, &renderer, &map);
}

void cleanGame(SDL_Window **window, SDL_Renderer **renderer, Map *map)
{
	SDL_Log("error : %s\n", SDL_GetError());

	for(int i = 0; i < map->width; i++)
	{
		if(map->tile[i] != NULL)
		{
			free(map->tile[i]);
			map->tile[i] = NULL;
		}
	}

	if(map->tile != NULL)
	{
		free(map->tile);
		map->tile = NULL;
	}

	if(*renderer != NULL)
	{
		SDL_DestroyRenderer(*renderer);
		*renderer = NULL;
	}
	if(*window != NULL)
	{
		SDL_DestroyWindow(*window);
		*window = NULL;
	}
	SDL_Quit();
}