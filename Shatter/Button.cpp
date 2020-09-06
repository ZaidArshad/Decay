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
	border.setFillColor(SECONDARY_COLOR);

	inside.setSize(sf::Vector2f(width, height));
	inside.setFillColor(Color::Blue);
	inside.setOrigin(inside.getLocalBounds().width / 2, inside.getLocalBounds().height / 2);
	inside.setPosition(xPosition, yPosition);
	inside.setFillColor(PRIMARY_COLOR);

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
	if (fontR==0 || fontR == 255) {
		colorIncrementer *= -1;
		fontR += colorIncrementer * 3;
		fontG += colorIncrementer * 3;
		fontB += colorIncrementer * 3;
	}
	else {
		fontR += colorIncrementer * 3;
		fontG += colorIncrementer * 3;
		fontB += colorIncrementer * 3;
	}
	std::cout << fontR << "\n";
	text.setFillColor(Color(fontR,fontG,fontB));
}