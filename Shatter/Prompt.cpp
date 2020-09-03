#include "Prompt.h"
#include <iostream>

Prompt::Prompt(float xPos, float yPos, string fontName, int fSize, string text, sf::Color color) {
	xPosition = xPos;
	yPosition = yPos;
	textString = text;
	textColor = color;
	fontSize = fSize;

	if (!font.loadFromFile("fonts/"+fontName))
		std::cout << "did not load\n";

	textObj.setFont(font);
	textObj.setString(textString);
	textObj.setCharacterSize(fontSize);
	textObj.setFillColor(color);
	textObj.setPosition(xPosition, yPosition);

}


sf::Text Prompt::getText() { return textObj; }
sf::Font Prompt::getFont() { return font; }