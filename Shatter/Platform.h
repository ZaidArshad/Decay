#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"

using namespace sf;

class Platform
{
public:
	// General attributes
	float width;
	float height;
	float originalHeight;
	float xPos;
	float yPos;
	sf::RectangleShape rectangleShape;

	// Unique number that each platform will get to differentiate from each other
	int platformId;

	//------Constructors------//
	Platform();
	Platform(float w, float h, float x, float y);

	//------Setters------//
	void setWidth(float w);
	void setHeight(float h);
	void setXPos(float x);
	void setYPos(float  y);
	void setPlatformId(int id);

	//------Getters------//
	float getWidth();
	float getHeight();
	float getOriginalHeight();
	float getXPos();
	float getYPos();
	int getPlatformId();
	sf::RectangleShape getShape();
};
