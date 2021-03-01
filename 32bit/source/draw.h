#ifndef __DRAW_H__
#define __DRAW_H__

#include "core.h"
#include "map.h"

SDL_bool draw(SDL_Renderer *renderer, Map map);
SDL_bool drawMap(SDL_Renderer *renderer, Map map);
SDL_bool setColor(SDL_Renderer *renderer, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
SDL_bool drawLine(SDL_Renderer *renderer, const int x1, const int y1, const int x2, const int y2);
SDL_bool drawLineWithColor(SDL_Renderer *renderer, const int x1, const int y1, const int x2, const int y2, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
SDL_bool drawRect(SDL_Renderer *renderer, const SDL_Rect *rect);
SDL_bool drawRectWithColor(SDL_Renderer *renderer, const SDL_Rect *rect, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
SDL_bool drawFillRect(SDL_Renderer *renderer, const SDL_Rect *rect);
SDL_bool drawFillRectWithColor(SDL_Renderer *renderer, const SDL_Rect *rect, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
SDL_bool drawPoint(SDL_Renderer *renderer, const int x, const int y);
SDL_bool drawPointWithColor(SDL_Renderer *renderer, const int x, const int y, const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);

#endif