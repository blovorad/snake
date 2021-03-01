#include "snake.h"

/*typedef struct 
{

	SDL_Rect dimension;
	SDL_Texture *texture;

}Body;

typedef struct
{
	int vx, vy;
}Speed;

typedef struct
{

	Body[450] body;
	int nbElement;
	int elementMax;
	Speed speed;

}Snake;
*/

void initSnake(Snake *snake)
{
	snake->nbElement = 3;
	snake->elementMax = MAX_SIZE;
	snake->speed.vx = -32;
	snake->speed.vy = 0;

	SDL_Rect r = {192, 96, 32, 32};
	SDL_Rect r2 = {224, 96, 32, 32};
	SDL_Rect r3 = {256, 96, 32, 32};

	snake->body[0].dimension = r;
	snake->body[0].texture = 0;
	snake->body[0].angle = 270;
	snake->body[0].center = NULL;
	snake->body[0].flip = SDL_FLIP_NONE;

	snake->body[1].dimension = r2;
	snake->body[1].texture = 1;
	snake->body[1].angle = 270;
	snake->body[1].center = NULL;
	snake->body[1].flip = SDL_FLIP_NONE;

	snake->body[2].dimension = r3;
	snake->body[2].texture = 2;
	snake->body[2].angle = 270;
	snake->body[2].center = NULL;
	snake->body[2].flip = SDL_FLIP_NONE;

}

void updateSnake(Snake *snake)
{
	snake->body[0].dimension.x += snake->speed.vx;
	snake->body[0].dimension.y += snake->speed.vy;
	for(int i = snake->nbElement - 1; i > 0; i--)
	{
		snake->body[i].dimension.x = snake->body[i - 1].dimension.x;
		snake->body[i].dimension.y = snake->body[i - 1].dimension.y;
		snake->body[i].angle = snake->body[i - 1].angle;
	}

	if(snake->body[0].dimension.x < 0)
	{
		snake->body[0].dimension.x = 800 - 32;
	}
}