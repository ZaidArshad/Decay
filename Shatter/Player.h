#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"

using namespace sf;

class Player
{
	float scale;
	float xPos;
	float yPos;
	int xSpeed;
	int ySpeed;
	Texture playerTexture;
	Sprite playerSprite;
	bool canJump;
	int jumpHeight;

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

	float  getScale();
	float  getXPos();
	float  getYPos();
	Texture getTexture();
	Sprite getSprite();
	int getXSpeed();
	int getYSpeed();
	bool getJump();
	int getJumpHeight();

	void move(float x, float y);
};
