#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Graphics;
struct RgbHolder;

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, RgbHolder &rgb, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics);
	void setX(float x);
	void setY(float y);
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
	float _x, _y;

};

#endif // !SPRITE_H

