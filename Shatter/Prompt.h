#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include <iostream>

using namespace std;

class Prompt
{
	float xPosition;
	float yPosition;
	string textString;
	sf::Color textColor;
	int fontSize;
	sf::Text textObj;
	sf::Font font;
	int fontR = 0;
	int fontG = 0;
	int fontB = 255;
	int alpha = 255;
	int colorIncrementer = 1;
	int iterator = 0;

public:
	Prompt(float xPos, float yPos, string fontName, int fSize, string text, sf::Color color);
	sf::Text getText();
	sf::Font getFont();
	void textColorShifter();
	void blink();
	sf::Color getColor();
};

