#include "Processes.h"
#include "Button.h"

Font loadFont(std::string fontFileName) {
	Font font;
	if (!font.loadFromFile("fonts/" + fontFileName))
		std::cout << "did not load\n";
	else { return font; }
}

void titleScreen(RenderWindow& window) {
	Button start(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y, "Shatter", "ka1.ttf");
	Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}
		start.draw(window);
	}
}