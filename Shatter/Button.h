#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include "Processes.h"
#include <iostream>

using namespace std;

class Button
{
	float xPosition;
	float yPosition;
	float width;
	float height;
	string name;
	sf::Text text;
	sf::Font font;
	sf::RectangleShape border;
	sf::RectangleShape inside;
	int fontR = 0;
	int fontG = 0;
	int fontB = 0;
	int colorIncrementer = -1;
	const Color PRIMARY_COLOR = Color(0,0,0);
	const Color SECONDARY_COLOR = Color(255, 255, 255);

public:
	Button(float xPos, float yPos, string title, string fontName);
	void draw(RenderWindow &window);
	void textColorShifter();
};

