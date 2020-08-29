#include "BreakPlatform.h"

BreakPlatform::BreakPlatform(int healt, float  w, float  h, float  x, float y) {
	health = healt;
	rectangleShape.setFillColor(healthIndex[healt - 1]);

	width = w;
	height = h;
	xPos = x;
	yPos = y;
	rectangleShape.setSize(Vector2f(width, height));
	rectangleShape.setPosition(xPos, yPos);
}

bool BreakPlatform::getIsTouched() { return isTouched; }

void BreakPlatform::setIsTouched(bool status) { isTouched = status; }

void BreakPlatform::touched() {
	health--;
	rectangleShape.setFillColor(healthIndex[health - 1]);

	if (health == 0) {
		rectangleShape.setSize(Vector2f(0,0));
	}
}
int BreakPlatform::getHealth() { return health; }
