#include "update.h"

SDL_bool update(Input *input, Snake *snake)
{
	updateSnake(snake);

	return updateInput(input);
}