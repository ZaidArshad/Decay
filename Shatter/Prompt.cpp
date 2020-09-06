#include "Prompt.h"
#include "Processes.h"

Prompt::Prompt(float xPos, float yPos, string fontName, int fSize, string text, sf::Color color) {
	xPosition = xPos;
	yPosition = yPos;
	textString = text;
	textColor = color;
	fontSize = fSize;

	font = loadFont(fontName);

	textObj.setFont(font);
	textObj.setString(textString);
	textObj.setCharacterSize(fontSize);
	textObj.setFillColor(color);
	textObj.setPosition(xPosition, yPosition);

}


sf::Text Prompt::getText() { return textObj; }
sf::Font Prompt::getFont() { return font; }