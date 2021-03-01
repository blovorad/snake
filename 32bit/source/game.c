#include "game.h"


void launchGame(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	Uint32 flag = SDL_INIT_EVERYTHING;
	SDL_BlendMode blendMode = SDL_BLENDMODE_BLEND;
	Input input;
	Map map;
	Snake snake;
	SDL_Texture *texture[MAX_TEXTURE];
	map.width = 0;

	SDL_bool go = init(flag, blendMode, &window, &renderer, &input, &map, &snake, texture);

	while(go)
	{
		go = update(&input, &snake);
		if(go)
		{
			go = draw(renderer, map, snake, texture);
		}
	}

	cleanGame(&window, &renderer, &map, texture);
}

void cleanGame(SDL_Window **window, SDL_Renderer **renderer, Map *map, SDL_Texture *texture[])
{
	SDL_Log("error : %s\n", SDL_GetError());

	for(int i = 0; i < MAX_TEXTURE; i++)
	{
		if(texture[i] != NULL)
		{
			SDL_DestroyTexture(texture[i]);
			texture[i] = NULL;
		}
	}

	SDL_Log("clean texture ok\n");

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

	SDL_Log("clean map ok\n");

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
	IMG_Quit();
	SDL_Quit();
	SDL_Log("everything is clean\n");
}