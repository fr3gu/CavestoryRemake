#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Player {

public:
	Player();
	AnimatedSprite getSprite();
	void init(Graphics &graphics);
	void init(Graphics &graphics, float posX, float posY);
	void playAnimation(std::string animation);
	void update(float elapsedTime);
	void draw(Graphics &graphics);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stop();
	void animationDone(string currentAnimation);
	const float getX() const;
	const float getY() const;
private:
	AnimatedSprite _sprite;
	float _dx, _dy;
	Direction _facing;
	bool _isGrounded;
};
#endif // !1

