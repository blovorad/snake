#include "input.h"

void initInput(Input *input)
{
	input->z = SDL_FALSE;
	input->s = SDL_FALSE;
	input->q = SDL_FALSE;
	input->d = SDL_FALSE;
	input->escape = SDL_FALSE;
}

SDL_bool updateInput(Input *input)
{
	SDL_Event event;
	SDL_bool noQuitGame = SDL_TRUE;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				noQuitGame = SDL_FALSE;
				break;

			case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_z)
					{
						input->z = SDL_TRUE;
					}
					if(event.key.keysym.sym == SDLK_d)
					{
						input->d = SDL_TRUE;
					}
					if(event.key.keysym.sym == SDLK_s)
					{
						input->s = SDL_TRUE;
					}
					if(event.key.keysym.sym == SDLK_q)
					{
						input->q = SDL_TRUE;
					}
					if(event.key.keysym.sym == SDLK_ESCAPE)
					{
						input->escape = SDL_TRUE;
					}
				break;

			case SDL_KEYUP:
					if(event.key.keysym.sym == SDLK_z)
					{
						input->z = SDL_FALSE;
					}
					if(event.key.keysym.sym == SDLK_d)
					{
						input->d = SDL_FALSE;
					}
					if(event.key.keysym.sym == SDLK_s)
					{
						input->s = SDL_FALSE;
					}
					if(event.key.keysym.sym == SDLK_q)
					{
						input->q = SDL_FALSE;
					}
					if(event.key.keysym.sym == SDLK_ESCAPE)
					{
						input->escape = SDL_FALSE;
					}
				break;

			default:
				break;
		}
	}

	return noQuitGame;
}