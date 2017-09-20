#include "animatedsprite.h"
#include "graphics.h"

using namespace std;

AnimatedSprite::AnimatedSprite()
{
}

AnimatedSprite::AnimatedSprite(Graphics & graphics, const std::string & filePath, RgbHolder & rgb, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, rgb, sourceX, sourceY, width, height, posX, posY),
	_frameIndex(0),
	_timeToUpdate(timeToUpdate),
	_isVisible(true),
	_currentAnimationOnce(false),
	_currentAnimation(""),
	_timeElapsed(0)
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset)
{
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect rect = { (i + x) * width, y, width, height };
		rectangles.push_back(rect);
	}
	this->_animations.insert(pair<string, vector<SDL_Rect>>(name, rectangles));
	this->_offsets.insert(pair<string, Vector2>(name, offset));
}
void AnimatedSprite::addAnimationVert(int frames, int x, int y, string name, int width, int height, Vector2 offset)
{
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect rect = { x, (i + y) * width, width, height };
		rectangles.push_back(rect);
	}
	this->_animations.insert(pair<string, vector<SDL_Rect>>(name, rectangles));
	this->_offsets.insert(pair<string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimations()
{
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once)
{
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation) {
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimatedSprite::setIsVisible(bool isVisible)
{
	this->_isVisible = isVisible;
}

void AnimatedSprite::stopAnimation()
{
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimatedSprite::update(float elapsedTime)
{
	Sprite::update();
	this->_timeElapsed += elapsedTime;
	if (this->_timeElapsed > this->_timeToUpdate) {
		this->_timeElapsed -= this->_timeToUpdate;

		if (this->_frameIndex < ((int)this->_animations[this->_currentAnimation].size()) - 1) {
			this->_frameIndex++;
		}
		else {
			if (this->_currentAnimationOnce) {
				this->setIsVisible(false);

			}
			this->_frameIndex = 0;
			this->animationDone(this->_currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics& graphics)
{
	if (this->_isVisible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = (int)this->_x + this->_offsets[this->_currentAnimation].x;
		destinationRectangle.y = (int)this->_y + this->_offsets[this->_currentAnimation].y;
		destinationRectangle.w = (int)(this->_sourceRect.w * globals::SPRITE_SCALE);
		destinationRectangle.h = (int)(this->_sourceRect.h * globals::SPRITE_SCALE);

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];

		graphics.blitSurface(this->_spriteSheet, &sourceRect, &destinationRectangle);
	}
}

//void AnimatedSprite::setupAnimations()
//{
//	
//}


void AnimatedSprite::animationDone(string currentAnimation)
{
}
