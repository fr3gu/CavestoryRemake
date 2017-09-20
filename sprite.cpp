#include "sprite.h"
#include "globals.h"
#include "graphics.h"

Sprite::Sprite()
{
}

Sprite::Sprite(Graphics & graphics, const std::string & filePath, RgbHolder & rgb, int sourceX, int sourceY, int width, int height, float posX, float posY) : _x(posX), _y(posY) {

	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath, rgb));
	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite()
{
}

void Sprite::update()
{
}

void Sprite::draw(Graphics & graphics)
{
	SDL_Rect destinationRectangle = { this->_x, this->_y, this->_sourceRect.w * globals::SPRITE_SCALE, this->_sourceRect.h * globals::SPRITE_SCALE };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::setX(float x)
{
	if ((_x + x) + (16 * globals::SPRITE_SCALE) < globals::SCREEN_WIDTH && (_x + x) > 0)  {
		this->_x += x;
	}
}

void Sprite::setY(float y)
{
	if ((_y + y) + (16 * globals::SPRITE_SCALE) < globals::SCREEN_HEIGTH && (_y + y) > 0) {
		this->_y += y;
	}
}
