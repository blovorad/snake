#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "core.h"

#define MAX_SIZE 450;

typedef struct 
{

	SDL_Rect dimension;
	int texture;
	double angle;
	SDL_Point *center;
	SDL_RendererFlip flip;

}Body;

typedef struct
{
	int vx, vy;
}Speed;

typedef struct
{

	Body body[450];
	int nbElement;
	int elementMax;
	Speed speed;

}Snake;

void initSnake(Snake *snake);
void updateSnake(Snake *snake);

#endif