
#include"Platform.h"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"


using namespace sf;

// Default constructor
Platform::Platform() {
	width = 0;
	height = 0;
	xPos = 0;
	yPos = 0;
}

// Regular constructor
Platform::Platform(float  w, float  h, float  x, float y) {
	width = w;
	height = h;
	originalHeight = h;
	xPos = x;
	yPos = y;
	rectangleShape.setSize(Vector2f(width, height));
	rectangleShape.setPosition(xPos, yPos); 
}

//------Setters------//
void Platform::setWidth(float  w){
	width = w;
	rectangleShape.setSize(Vector2f(width, height));
}
void Platform::setHeight(float h) {
	height = h;
	rectangleShape.setSize(Vector2f(width, height));
}
void Platform::setXPos(float  x) {
	xPos = x;
	rectangleShape.setPosition(xPos, yPos);
}
void Platform::setYPos(float  y) {
	yPos = y;
	rectangleShape.setPosition(xPos, yPos);
}

// Sets the unique number to differentiate between platforms
void Platform::setPlatformId(int id) { platformId = id; }

//------Getters------//
float  Platform::getWidth() { return width; }
float  Platform::getHeight() { return height; }
float Platform::getOriginalHeight() { return originalHeight; }
float Platform::getXPos() { return xPos; }
float Platform::getYPos() { return yPos; }

// Gets the unique number used to diferentiate between platforms in the level
int Platform::getPlatformId() { return platformId; }

// Gets the drawable object from the platform
RectangleShape Platform::getShape() { return rectangleShape; }
