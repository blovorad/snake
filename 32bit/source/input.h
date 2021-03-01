#ifndef __INPUT_H__
#define __INPUT_H__

#include "core.h"

typedef struct 
{
	SDL_bool z,q,s,d,escape;
}Input;

void initInput(Input *input);
SDL_bool updateInput(Input *input);

#endif