#include "Button.h"

Button::Button(float xPos, float yPos, string title, string fontName) {
	const int MARGIN = 50; //space around text from button
	const int BORDER_WIDTH = 10; //border width
	xPosition = xPos;
	yPosition = yPos;
	font = loadFont(fontName);
	name = title;



	text.setString(name);
	text.setFont(font);
	text.setFillColor(Color(fontR,fontG,fontB));

	width = text.getLocalBounds().width + MARGIN; //width of total button
	height = text.getLocalBounds().height + MARGIN; //height of total button
	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);

	border.setSize(sf::Vector2f(width+BORDER_WIDTH,height+ BORDER_WIDTH));
	border.setFillColor(Color::White);
	border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
	border.setPosition(xPosition, yPosition);
	border.setFillColor(Color::White);

	inside.setSize(sf::Vector2f(width, height));
	inside.setFillColor(Color::Blue);
	inside.setOrigin(inside.getLocalBounds().width / 2, inside.getLocalBounds().height / 2);
	inside.setPosition(xPosition, yPosition);
	inside.setFillColor(Color::Black);

	text.setPosition(inside.getPosition().x, inside.getPosition().y-5);

}

void Button::draw(RenderWindow& window) {
	window.clear(Color::Black);
	window.draw(border);
	window.draw(inside);
	textColorShifter();
	window.draw(text);
	window.display();
}

void Button::textColorShifter() {
	if (iterator < 255 && iterator >= 0) {
		fontR++;
		fontB--;
	}
	else if (iterator < 510 && iterator >= 255) {
		fontG++;
		fontR--;
	}
	else if (iterator < 765 && iterator >= 510) {
		fontB++;
		fontG--;
	}
	else { iterator = -1; }
	iterator++;
	text.setFillColor(Color(fontR,fontG,fontB));
	border.setFillColor(Color(fontR, fontG, fontB));

}