#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "globals.h"

/* Graphics class
*
*/


Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGTH, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory++");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface * Graphics::loadImage(const std::string & filePath, RgbHolder & rgb)
{
	const char* thePath = filePath.c_str();
	if (this->_spriteSheets.count(filePath) == 0) {
		SDL_Surface* surfejs = IMG_Load(thePath);
		if(rgb.isSet) {
			SDL_SetColorKey(surfejs, 1, SDL_MapRGB(surfejs->format, rgb.r, rgb.g, rgb.b));
		}		
		SDL_Log("Graphics::loagImage IMG_GetError: %s", IMG_GetError());
		SDL_Log("Graphics::loagImage SDL_GetError: %s", SDL_GetError());
		this->_spriteSheets[filePath] = surfejs;
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture * texture, SDL_Rect * sourceRectangle, SDL_Rect * destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer * Graphics::getRenderer() const
{
	return this->_renderer;
}
