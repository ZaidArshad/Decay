#include "Button.h"

Button::Button(float xPos, float yPos, string title, string fontName) {

	// Position and size data
	xPosition = xPos;
	yPosition = yPos;
	const int MARGIN = 50; //Space around text from button
	const int BORDER_WIDTH = 10; //Border width

	// Loads font in scope
	font = loadFont(fontName);

	// Setting Attributes
	name = title;

	// Building text object
	text.setString(name);
	text.setCharacterSize(50);
	text.setFont(font);
	text.setFillColor(Color::White);

	// Adjusting the total width/height to match the button's with margin
	width = text.getLocalBounds().width + MARGIN; 
	height = text.getLocalBounds().height + MARGIN; 

	// Setting the origin to the middle of the button
	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);

	// Building border around button
	border.setSize(sf::Vector2f(width+BORDER_WIDTH,height+ BORDER_WIDTH));
	border.setFillColor(Color::White);
	border.setOrigin(border.getLocalBounds().width / 2, border.getLocalBounds().height / 2);
	border.setPosition(xPosition, yPosition);
	border.setFillColor(Color::White);

	// Building inner portion of button
	inside.setSize(sf::Vector2f(width, height));
	inside.setFillColor(Color::Blue);
	inside.setOrigin(inside.getLocalBounds().width / 2, inside.getLocalBounds().height / 2);
	inside.setPosition(xPosition, yPosition);
	inside.setFillColor(Color::Black);

	// Set the position of the text into the middle of the button
	text.setPosition(inside.getPosition().x, inside.getPosition().y-5);

}

// Draws the entire button the screen
void Button::draw(RenderWindow& window) {
	window.draw(border);
	window.draw(inside);
	window.draw(text);
}

// Changes the color to the button in different ways
void Button::textColorShifter() {
	// As r goes up, b goes down
	if (iterator < 255 && iterator >= 0) {
		fontR++;
		fontB--;
	}

	// As g goes up, r goes down
	else if (iterator < 510 && iterator >= 255) {
		fontG++;
		fontR--;
	}

	// As b goes up, g goes down
	else if (iterator < 765 && iterator >= 510) {
		fontB++;
		fontG--;
	}

	else { iterator = -1; }

	// Iterator is the individual step the the function is on goes to 255 on each rgb color then goes down
	iterator++;

	// Adjusting the color of the border and text
	text.setFillColor(Color(fontR,fontG,fontB));
	border.setFillColor(Color(fontR, fontG, fontB));
}

// Allows the mouse to interact with the button (highlights and when clicked return true)
bool Button::mouseInteract(RenderWindow &window) {
	// Gets current mouse attributes
	Mouse mouse;

	// If the button is in contact with the mouse color it
	if (border.getGlobalBounds().contains(mouse.getPosition(window).x, mouse.getPosition(window).y)) {
		border.setFillColor(Color::Black);
		inside.setFillColor(Color::White);
		text.setFillColor(Color::Black);

		// If left mouse button is clicked
		if (mouse.isButtonPressed(Mouse::Button::Left))
			return true;
	}
	else {
		// Sets the button's color to the default
		border.setFillColor(Color::White);
		inside.setFillColor(Color::Black);
		text.setFillColor(Color::White);
		return false;
	}
}

// Sets the opacity of the button
void Button::setAlpha(int opacity) {
	border.setFillColor(Color(border.getFillColor().r, border.getFillColor().g, border.getFillColor().b, opacity));
	inside.setFillColor(Color(inside.getFillColor().r, inside.getFillColor().g, inside.getFillColor().b, opacity));
	text.setFillColor(Color(text.getFillColor().r, text.getFillColor().g, text.getFillColor().b, opacity));
}