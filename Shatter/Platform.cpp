#include"Platform.h"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"


using namespace sf;

Platform::Platform(float  w, float  h, float  x, float y) {
	width = w;
	height = h;
	xPos = x;
	yPos = y;
	rectangleShape.setSize(Vector2f(width, height));
	rectangleShape.setPosition(xPos, yPos);
}
void Platform::setWidth(float  w) {
	width = w;
	rectangleShape.setSize(Vector2f(*&width, *&height));
}
void Platform::setHeight(float h) {
	height = h;
	rectangleShape.setSize(Vector2f(*&width, *&height));
}

void Platform::setXPos(float  x) {
	xPos = x;
	rectangleShape.setPosition(xPos, yPos);
}
void Platform::setYPos(float  y) {
	yPos = y;
	rectangleShape.setPosition(xPos, yPos);
}

float  Platform::getWidth() { return width; }
float  Platform::getHeight() { return height; }
float Platform::getXPos() { return xPos; }
float Platform::getYPos() { return yPos; }
RectangleShape Platform::getShape() { return rectangleShape;}

























