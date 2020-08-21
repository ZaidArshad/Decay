#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"

using namespace sf;

class Player
{
	float scale;
	float xPos;
	float yPos;
	int speed;
	Texture playerTexture;
	Sprite playerSprite;

public:
	Player(float x, float y, float s);
	void setScale(float s);
	void setXPos(float x);
	void setYPos(float  y);
	void setTexture(Texture &texture);
	void setSpeed(int vel);
	float  getScale();
	float  getXPos();
	float  getYPos();
	Texture getTexture();
	Sprite getSprite();
	int getSpeed();
	void move(float x, float y);
};
