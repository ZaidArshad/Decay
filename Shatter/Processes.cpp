#pragma once
#include "Processes.h"
#include "Button.h"
#include "Prompt.h"
// This file is used to define general functions throughout the game


// Loads font in scope from a .ttf file
// fontFileName: the name of the font file that is to be loaded
// Returns: nothing
Font loadFont(std::string fontFileName) {
	Font font;
	// If the font does not load
	if (!font.loadFromFile("fonts/" + fontFileName))
		std::cout << "did not load\n";
	else { return font; }
}

// Proccess of the title screen
// window: Window that is openned in the beginning of the game
// Returns: nothing
void titleScreen(RenderWindow& window) {
	Event event; // Keep track of any input
	bool isStarted = false; // Keeps track if the user has chosen an input to start the game
	Prompt title(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "DECAY", sf::Color::White);
	Prompt pressSpace(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "Press start", sf::Color::White);

	// While the user has not chosen an option
	while (window.isOpen() && !isStarted) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			// Close game if escape is pressed
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
			// Enable the game to be started when space is pressed
			if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Space) || (Joystick::isButtonPressed(0, 7)))
				isStarted = true;
		}
		window.clear(Color::Black);

		// Makes texts pretty
		pressSpace.blink();
		pressSpace.textColorShifter();
		title.textColorShifter();

		// Draws the text
		window.draw(pressSpace.getText());
		window.draw(title.getText());
		window.display();
	}
}

// Proccess of the pause screen
// window: Window that is openned in the beginning of the game
// restartState: boolean variable that checks if the level should be restarted in the main loop
// Returns: nothing
void pauseScreen(RenderWindow& window, bool &restartState) {
	bool isPaused = true; // Keeps track if the player chooses to resume the game

	bool canPressStart = false; // Checks if the user's controller can press start
	int yPos; // Position of the user's controller left stick y axis
	int option = -1; // Option for the menu of the controller
	bool canSelect = true;

	Event event; // Keeps track of any inputs

	// The buttons on the pause screen
	Button resumeButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-120, "Resume", "bulkypix.ttf");
	Button restartButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y, "Restart", "bulkypix.ttf");
	Button quitButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+120, "Quit", "bulkypix.ttf");

	// Prompt object only used for it's textColorShifter() function
	Prompt backgroundColor(0, 0, "ka1.ttf" ,30 , " ", Color::Black);
	int blue = 0; // Used for a smooth transition in background color
	Color bgColor(0, 0, blue);

	while (window.isOpen() && isPaused) {
		isPaused = !resumeButton.mouseInteract(window); // If the user clicks the resume button

		// When the user pressed the resume button
		if (restartButton.mouseInteract(window)) {
			isPaused = false;
			restartState = true; // Inform the main loop to restart the level
		}

		// Controls the menu with the controller
		if (Joystick::isConnected(0)) {
			yPos = Joystick::getAxisPosition(0, Joystick::Y);

			// Selecting options
			if (yPos < -20 && option > -1 && canSelect) {
				option--;
				Mouse::setPosition(Vector2i(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y + 120 * option), window);
				canSelect = false;
			}
			else if (yPos > 20 && option < 1 && canSelect) {
				option++;
				Mouse::setPosition(Vector2i(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y + 120 * option), window);
				canSelect = false;
			}
			else if (yPos < 20 && yPos > -20)
				canSelect = true;

			// Pressing A on the options
			if (Joystick::isButtonPressed(0, 0)) {
				if (option == -1)
					isPaused = false;
				else if (option == 0) {
					isPaused = false;
					restartState = true; // Inform the main loop to restart the level
				}
				else if (option == 1)
					window.close();
			}
		}



		// Closes the game if escape or the quit button are pressed
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed || quitButton.mouseInteract(window))
				window.close();
			if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || (Joystick::isButtonPressed(0, 7) && canPressStart))
				isPaused = false;
			if (event.type == Event::JoystickButtonReleased && event.joystickButton.button != Joystick::isButtonPressed(0, 7))
				canPressStart = true;
		}

		// Transition from black to blue background
		if (blue < 255) {
			blue++;
			bgColor.b = blue;
			window.clear(bgColor);
		}
		// Transisiton between different colour background
		else {
			backgroundColor.textColorShifter();
			window.clear(backgroundColor.getColor());
		}

		// Draws the button
		resumeButton.draw(window);
		restartButton.draw(window);
		quitButton.draw(window);
		window.display();
	}
}

// Transition between levels or restart
// window: Window that is openned in the beginning of the game
// level: The integer value of what level the user is on
// score: The integer value of the score that they've accumulated
// Returns: nothing
void fade(RenderWindow& window, int level, int score) {
	RectangleShape screenOverlay(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)); // Block that fades onto the screen
	screenOverlay.setPosition(0, 0);
	// Text that fades in
	Prompt levelPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "Level " + std::to_string(level + 1), Color::White);
	Prompt scorePrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "Total Score  " + std::to_string(score), Color::White);

	// Fading into black for background and white for text
	for (int alpha = 0; alpha <= 255; alpha += 8) {
		screenOverlay.setFillColor(Color(0, 0, 0, alpha));
		levelPrompt.setColor(Color(255, 255, 255, alpha));
		scorePrompt.setColor(Color(255, 255, 255, alpha));

		// Draws the text and block
		window.draw(screenOverlay);
		window.draw(levelPrompt.getText());
		window.draw(scorePrompt.getText());
		window.display();
	}
}

// Appears when the user dies
// window: Window that is openned in the beginning of the game
// Returns: nothing
void deathPrompt(RenderWindow& window) {
	bool isDead = true; // Checks if the user pressed R
	// Text that shows the user they have died
	Prompt deadPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y-50, "bulkypix.ttf", 100, "YOU DIED", Color::White);
	Prompt restartPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y+50, "ka1.ttf", 30, "press r to restart", Color::White);

	// While the user takes no action
	while (isDead) {
		// Make text pretty
		deadPrompt.textColorShifter();
		restartPrompt.textColorShifter();
		// Draw the text
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

// When the user completes the game
// window: Window that is openned in the beginning of the game
// score: Integer value of the players score
// Returns: nothing
void gameOverScreen(RenderWindow& window, int score) {
	bool isPaused = true; // Keeps track if the player chooses to resume the game
	Event event; // Keeps track of any inputs

	RectangleShape screenOverlay(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)); // Block that fades onto the screen

	// Text on the screen
	Prompt gameOverPrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y - 50, "bulkypix.ttf", 100, "GAME OVER", Color::White);
	Prompt scorePrompt(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y + 50, "ka1.ttf", 30, "Total Score  " + std::to_string(score), Color::White);

	// The buttons on the pause screen
	Button quitButton(MIDDLE_OF_SCREEN_X, MIDDLE_OF_SCREEN_Y + 200, "Quit", "bulkypix.ttf");

	// Prompt object only used for it's textColorShifter() function
	Prompt backgroundColor(0, 0, "ka1.ttf", 30, " ", Color::Black);
	int blue = 0; // Used for a smooth transition in background color
	Color bgColor(0, 0, blue);

	// Fades into black
	for (int alpha = 0; alpha <= 255; alpha += 8) {
		screenOverlay.setFillColor(Color(0, 0, 0, alpha));
		gameOverPrompt.setColor(Color(255, 255, 255, alpha));
		scorePrompt.setColor(Color(255, 255, 255, alpha));
		quitButton.setAlpha(alpha);

		// Draws the text and block
		window.draw(screenOverlay);
		quitButton.draw(window);
		window.draw(gameOverPrompt.getText());
		window.draw(scorePrompt.getText());
		window.display();
	}

	// While the user has not chosen and option
	while (window.isOpen() && isPaused) {

		// Closes the game if escape or the quit button are pressed
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed || quitButton.mouseInteract(window))
				window.close();

			// Transitions from black to blue
			if (blue < 255) {
				blue++;
				bgColor.b = blue;
				window.clear(bgColor);
			}
			// Transisiton between different colour background
			else {
				backgroundColor.textColorShifter();
				window.clear(backgroundColor.getColor());
			}

			// Draws the button
			quitButton.draw(window);
			window.draw(gameOverPrompt.getText());
			window.draw(scorePrompt.getText());
			window.display();
		}
	}
}