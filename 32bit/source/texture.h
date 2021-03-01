#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "core.h"

#define MAX_TEXTURE 4

SDL_bool initTexture(SDL_Renderer *renderer, SDL_Texture *texture[]);
SDL_Texture *createTexture(SDL_Renderer *renderer, char *chemin);
SDL_Texture *getTexture(int indice, SDL_Texture *texture[]);

#endif