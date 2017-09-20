#include "player.h"

namespace PlayerConstants {
	const float WALK_SPEED = 0.2f;
}

AnimatedSprite Player::getSprite()
{
	return _sprite;
}

void Player::init(Graphics &graphics)
{ 
	this->init(graphics, 100, 100);
}

void Player::init(Graphics &graphics, float posX, float posY)
{
	this->_sprite = AnimatedSprite(graphics, "MyChar.png", RgbHolder(0,0,0), 0, 0, 16, 16, posX, posY, 100);
	this->_sprite.addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2::zero());
	this->_sprite.addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2::zero());
	this->_sprite.addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2::zero());
	this->_sprite.addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2::zero());
	this->_sprite.addAnimationVert(2, 96, 0, "RunUp", 16, 16, Vector2::zero());
	this->_sprite.addAnimationVert(2, 112, 0, "RunDown", 16, 16, Vector2::zero());

	this->_sprite.playAnimation("RunRight");
}

void Player::playAnimation(std::string animation)
{
	this->_sprite.playAnimation(animation);
}

void Player::update(float elapsedTime)
{
	this->_sprite.setX(this->_dx * elapsedTime);
	this->_sprite.setY(this->_dy * elapsedTime);
	this->_sprite.update(elapsedTime);
}

void Player::draw(Graphics & graphics)
{
	this->_sprite.draw(graphics);
}

void Player::animationDone(string currentAnimation)
{
}

void Player::moveLeft()
{
	this->_dx = -PlayerConstants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight()
{
	this->_dx = PlayerConstants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::moveUp()
{
	this->_dy = -PlayerConstants::WALK_SPEED;
	this->playAnimation("RunUp");
	this->_facing = UP;
}

void Player::moveDown()
{
	this->_dy = PlayerConstants::WALK_SPEED;
	this->playAnimation("RunDown");
	this->_facing = DOWN;
}

void Player::stop()
{
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	this->playAnimation(this->_facing == LEFT ? "IdleLeft" : "IdleRight");
}

