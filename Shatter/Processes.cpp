#pragma once
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
	Prompt title(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "DECAY", sf::Color::White);
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

void pauseScreen(RenderWindow& window, bool &restartState) {
	bool isPaused = true;
	Event event;
	Button resumeButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-120, "Resume", "bulkypix.ttf");
	Button restartButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y, "Restart", "bulkypix.ttf");
	Button quitButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+120, "Quit", "bulkypix.ttf");
	Prompt backgroundColor(0, 0, "ka1.ttf" ,30 , " ", Color::Black);
	int blue = 0;
	Color bgColor(0, 0, blue);

	while (window.isOpen() && isPaused) {
		isPaused = !resumeButton.mouseInteract(window);


		if (restartButton.mouseInteract(window)) {
			isPaused = false;
			restartState = true;
		}

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed || quitButton.mouseInteract(window))
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				isPaused = false;
		}

		if (blue < 255) {
			blue++;
			bgColor.b = blue;
			window.clear(bgColor);
		}
		else {
			backgroundColor.textColorShifter();
			window.clear(backgroundColor.getColor());
		}

		resumeButton.draw(window);
		restartButton.draw(window);
		quitButton.draw(window);
		window.display();
	}
}

void fade(RenderWindow& window, int level, int score) {

	RectangleShape screenOverlay(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	screenOverlay.setPosition(0, 0);
	Prompt levelPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "Level " + std::to_string(level + 1), Color::White);
	Prompt scorePrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "Total Score  " + std::to_string(score), Color::White);

	for (int alpha = 0; alpha <= 255; alpha += 8) {
		screenOverlay.setFillColor(Color(0, 0, 0, alpha));
		levelPrompt.setColor(Color(255, 255, 255, alpha));
		scorePrompt.setColor(Color(255, 255, 255, alpha));
		window.draw(screenOverlay);
		window.draw(levelPrompt.getText());
		window.draw(scorePrompt.getText());
		window.display();
	}
}

// Appears when the user dies
void deathPrompt(RenderWindow& window) {
	// Checks if the user pressed R
	bool isDead = true;
	Prompt deadPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "YOU DIED", Color::White);
	Prompt restartPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "press r to restart", Color::White);

	while (isDead) {
		deadPrompt.textColorShifter();
		restartPrompt.textColorShifter();
		window.draw(deadPrompt.getText());
		window.draw(restartPrompt.getText());
		window.display();

		// If the "R" key is pressed continue the game
		if (Keyboard::isKeyPressed(Keyboard::R))
			isDead = false;
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();
	}
}