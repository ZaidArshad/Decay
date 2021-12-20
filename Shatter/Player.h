#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include"Processes.h"

using namespace sf;

class Player
{
	// General Attributes
	float scale;
	float xPos;
	float yPos;

	// Velocity
	int xSpeed;
	int ySpeed;

	// Visual Attributes
	Texture playerTexture;
	Texture canSpriteSheet;
	Sprite playerSprite;

	// Jumping Attributes
	bool canJump;
	float jumpHeight;
	bool wHeld;
	int platformId;

	// Animation Attributes
	int rollingSpriteId;
	int frame;

public:
	//------Constructors------//
	Player(Vector2f startPosition, float scale);

	//------Setters------//
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

	//------Getters------//
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

	//------Other------//
	void move(float x, float y);
	void animateRolling(String direction);
};
