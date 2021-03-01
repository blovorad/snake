#include "draw.h"

SDL_bool draw(SDL_Renderer *renderer, Map map)
{
	if(!setColor(renderer, 0, 0, 0, 0))
	{
		return SDL_FALSE;
	}

	if(SDL_RenderClear(renderer) < 0)
	{
		return SDL_FALSE;
	}
	SDL_Rect r = {200, 200, 50, 50};
	SDL_Rect r2 = {400, 400, 50, 50};

	if(!drawMap(renderer, map))
	{
		return SDL_FALSE;
	}


	SDL_RenderPresent(renderer);

	SDL_Delay(1);

	return SDL_TRUE;
}

SDL_bool setColor(SDL_Renderer *renderer, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	if(SDL_SetRenderDrawColor(renderer, r, g, b, a) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawLine(SDL_Renderer *renderer, const int x1, const int y1, const int x2, const int y2)
{	
	if(SDL_RenderDrawLine(renderer, x1, y1, x2, y2) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawLineWithColor(SDL_Renderer *renderer, const int x1, const int y1, const int x2, const int y2, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	if(!setColor(renderer, r, g, b, a))
	{
		return SDL_FALSE;
	}
	
	if(SDL_RenderDrawLine(renderer, x1, y1, x2, y2) < 0)
	{
		return SDL_FALSE;
	}	
	
	return SDL_TRUE;
}

SDL_bool drawRect(SDL_Renderer *renderer, const SDL_Rect *rect)
{
	if(SDL_RenderDrawRect(renderer, rect) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawRectWithColor(SDL_Renderer *renderer, const SDL_Rect *rect, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	if(!setColor(renderer, r, g, b, a))
	{
		return SDL_FALSE;
	}

	if(SDL_RenderDrawRect(renderer, rect) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawFillRect(SDL_Renderer *renderer, const SDL_Rect *rect)
{
	if(SDL_RenderFillRect(renderer, rect) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawFillRectWithColor(SDL_Renderer *renderer, const SDL_Rect *rect, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	if(!setColor(renderer, r, g, b, a))
	{
		return SDL_FALSE;
	}

	if(SDL_RenderFillRect(renderer, rect) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawPoint(SDL_Renderer *renderer, const int x, const int y)
{
	if(SDL_RenderDrawPoint(renderer, x, y) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawPointWithColor(SDL_Renderer *renderer, const int x, const int y, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	if(!setColor(renderer, r, g, b, a))
	{
		return SDL_FALSE;
	}

	if(SDL_RenderDrawPoint(renderer, x, y) < 0)
	{
		return SDL_FALSE;
	}

	return SDL_TRUE;
}

SDL_bool drawMap(SDL_Renderer *renderer, Map map)
{

	for(int y = 0; y < map.height; y++)
	{
		for(int x = 0; x < map.width; x++)
		{
			if(!drawRectWithColor(renderer, &map.tile[y][x].dimension, map.tile[y][x].color.r, map.tile[y][x].color.g, map.tile[y][x].color.b, map.tile[y][x].color.a))
			{
				return SDL_FALSE;
			}
		}
	}

	return SDL_TRUE;
}