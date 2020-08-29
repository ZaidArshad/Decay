#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"

using namespace sf;

class Platform
{
public:
	float width;
	float height;
	float xPos;
	float yPos;
	RectangleShape rectangleShape;

	Platform();
	Platform(float w, float h, float x, float y);
	void setWidth(float w);
	void setHeight(float h);
	void setXPos(float x);
	void setYPos(float  y);
	float  getWidth();
	float  getHeight();
	float  getXPos();
	float  getYPos();

	RectangleShape getShape();
};
