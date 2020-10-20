#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include"Processes.h"

using namespace sf;

class Player
{
	float scale;
	float xPos;
	float yPos;
	int xSpeed;
	int ySpeed;
	Texture playerTexture;
	Texture canSpriteSheet;
	Sprite playerSprite;
	bool canJump;
	float jumpHeight;
	int platformId;
	int rollingSpriteId;
	int frame;
	bool wHeld;

public:
	Player(float x, float y, float s);
	void setScale(float s);
	void setXPos(float x);
	void setYPos(float  y);
	void setTexture(Texture &texture);
	void setXSpeed(int xVel);
	void setYSpeed(int yVel);
	void setJump(bool jumped);
	void setJumpHeight();
	void setPlatformId(int id);
	void setSprite(Sprite sprite);
	void setWHeld(bool state);

	float  getScale();
	float  getXPos();
	float  getYPos();
	Texture getTexture();
	Sprite getSprite();
	int getXSpeed();
	int getYSpeed();
	bool getJump();
	float getJumpHeight();
	bool isOutside();
	bool getWHeld();
	int getPlatformId();

	void move(float x, float y);
	void animateRolling(String direction);
};
