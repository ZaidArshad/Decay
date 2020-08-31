#include "BreakPlatform.h"

BreakPlatform::BreakPlatform(int healt, float  w, float  h, float  x, float y) {
	health = healt;
	rectangleShape.setFillColor(healthIndex[healt]);

	width = w;
	height = h;
	xPos = x;
	yPos = y;
	rectangleShape.setSize(Vector2f(width, height));
	rectangleShape.setPosition(xPos, yPos);
	std::time_t timeOnLastTouch = std::time(nullptr);
}

bool BreakPlatform::getIsTouched() { return isTouched; }

void BreakPlatform::setIsTouched(bool status) { isTouched = status; }

void BreakPlatform::touched() {
	health--;
	rectangleShape.setFillColor(healthIndex[health]);
}

void BreakPlatform::setTimeOnLastTouch(std::time_t t) { timeOnLastTouch = t; }

void BreakPlatform::setHealth(int h) { health = h; };
int BreakPlatform::getHealth() { return health; }
void BreakPlatform::remove() { rectangleShape.setSize(Vector2f(0,0)); }

std::time_t BreakPlatform::getTimeOnLastTouch() { return timeOnLastTouch; }
