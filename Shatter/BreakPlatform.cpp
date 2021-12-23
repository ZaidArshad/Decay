#include "BreakPlatform.h"

BreakPlatform::BreakPlatform(int hp, float  w, float  h, float  x, float y) {

	// Health data
	health = hp;
	rectangleShape.setFillColor(healthIndex[hp]);

	// Position and size attributes
	width = w;
	height = h;
	originalHeight = h;
	xPos = x;
	yPos = y;

	// Setting position and size
	rectangleShape.setSize(Vector2f(width, height));
	rectangleShape.setPosition(xPos, yPos);
	rectangleShape.setOrigin(0, 0);
}


//------Setter Methods------//
void BreakPlatform::setIsTouched(bool status) { isTouched = status; }
void BreakPlatform::setHealth(int hp) { health = hp; };
void BreakPlatform::setTimeOnLastTouch(std::time_t t) { timeOnLastTouch = t; }

//------Getter Methods------//
bool BreakPlatform::getIsTouched() { return isTouched; }
int BreakPlatform::getHealth() { return health; }
std::time_t BreakPlatform::getTimeOnLastTouch() { return timeOnLastTouch; }


// Decreases the health of the platform and changes color
void BreakPlatform::touched() { 
	health--;
	rectangleShape.setFillColor(healthIndex[health]);
}

// Removes the platfrom from the screen but is still mutible
void BreakPlatform::remove() { rectangleShape.setSize(Vector2f(0, 0)); }








