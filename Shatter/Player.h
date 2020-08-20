#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"

using namespace sf;

class Player
{
	float scale;
	float xPos;
	float yPos;
	Texture playerTexture;
	Sprite playerSprite;

public:
	Player(float x, float y, float s);
	void setScale(float s);
	void setXPos(float x);
	void setYPos(float  y);
	void setTexture(Texture &texture);
	float  getScale();
	float  getXPos();
	float  getYPos();
	Texture getTexture();
	Sprite getSprite();
	void move(float x, float y);
};
