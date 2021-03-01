#include "texture.h"


SDL_bool initTexture(SDL_Renderer *renderer, SDL_Texture *texture[])
{
	texture[0] = createTexture(renderer, "source/graphic/snakeHead.png");
	texture[1] = createTexture(renderer, "source/graphic/snake.png");
	texture[2] = createTexture(renderer, "source/graphic/snakeQueue.png");
	texture[3] = createTexture(renderer, "source/graphic/pomme.png");

	if(texture[0] == NULL || texture[1] == NULL || texture[2] == NULL || texture[3] == NULL)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_Texture *createTexture(SDL_Renderer *renderer, char *chemin)
{
	SDL_Texture *texture;
	SDL_Surface *surface = IMG_Load(chemin);
	if(surface == NULL)
	{
		printf("IMG_Load :%s\n", IMG_GetError());
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	free(surface);
	surface = NULL;

	return texture;
}

SDL_Texture *getTexture(int indice, SDL_Texture *texture[])
{
	return texture[indice];
}