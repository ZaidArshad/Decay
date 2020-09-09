#include "Processes.h"
#include "Button.h"
#include "Prompt.h"

Font loadFont(std::string fontFileName) {
	Font font;
	if (!font.loadFromFile("fonts/" + fontFileName))
		std::cout << "did not load\n";
	else { return font; }
}

void titleScreen(RenderWindow& window) {
	Event event;
	bool isStarted = false;
	Prompt title(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "Shatter", sf::Color::White);
	Prompt pressSpace(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "Press space to start", sf::Color::White);

	while (window.isOpen() && !isStarted) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
				isStarted = true;
		}
		window.clear(Color::Black);

		pressSpace.blink();
		pressSpace.textColorShifter();
		window.draw(pressSpace.getText());
		title.textColorShifter();
		window.draw(title.getText());
		window.display();
	}
}

void pauseScreen(RenderWindow& window) {
	bool isPaused = true;
	Event event;
	Button resumeButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y, "Resume", "ka1.ttf");
	Prompt backgroundColor(0, 0, "ka1.ttf" ,30 , " ", Color::White);

	while (window.isOpen() && isPaused) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				isPaused = false;
		}
		resumeButton.mouseHover(window);
		backgroundColor.textColorShifter();
		window.clear(backgroundColor.getColor());
		resumeButton.draw(window);
		window.display();
	}
}