#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include "globals.h"
#include "sprite.h"
#include <vector>

using namespace std;

class Graphics;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const string &filePath, RgbHolder &rgb, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
	void playAnimation(string animation, bool once = false);
	void update(float elapsedTime);
	void draw(Graphics &graphics);
	//virtual void setupAnimations();
	void addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);
	void addAnimationVert(int frames, int x, int y, string name, int width, int height, Vector2 offset);
protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	string _currentAnimation;
	
	void resetAnimations();
	void stopAnimation();
	void setIsVisible(bool isVisible);
	virtual void animationDone(string currentAnimation);
private:
	map<string, vector<SDL_Rect>> _animations;
	map<string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _isVisible;
};

#endif // !ANIMATEDSPRITE_H
