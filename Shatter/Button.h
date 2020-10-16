#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include "Processes.h"
#include <iostream>

using namespace std;

class Button
{
	// Position and size attributes
	float xPosition;
	float yPosition;
	float width;
	float height;

	// Visual attributes
	string name;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape border;
	sf::RectangleShape inside;

	// Color attributes
	int fontR = 0;
	int fontG = 0;
	int fontB = 255;
	int iterator = 0;

public:
	//------Constructors------//
	Button(float xPos, float yPos, string title, string fontName);

	// Draws the entire button the screen
	void draw(RenderWindow &window);

	// Changes the color to the button in different ways
	void textColorShifter();

	// Allows the mouse to interact with the button (highlights and when clicked return true)
	bool mouseInteract(RenderWindow& window);
};

