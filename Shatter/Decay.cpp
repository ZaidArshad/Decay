#pragma once
#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Platform.h"
#include "Player.h"
#include "Game.h"
#include "BreakPlatform.h"
#include "Level.h"
#include "Prompt.h"
#include "Processes.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DECAY", sf::Style::Titlebar | sf::Style::Close);
	bool restartState = false;
	window.setFramerateLimit(60);
	Game game;
	titleScreen(window);
	fade(window, 0, 0);
	int frame = 0;

	// Score handeling
	int currentScore = 99;
	int totalScore = 0;
	Prompt currentScorePrompt(750, 50, "ka1.ttf", 30, "Score: " + currentScore, Color::White);


	for (int levelNumber = 1; levelNumber < 10; levelNumber++) {

		if (!window.isOpen())
			break;

		std::cout << "Level number: " << levelNumber << "\n";
		Player player(startPositions[levelNumber-1].x, startPositions[levelNumber-1].y, 1);
		Level level(levelNumber);
		std::vector<Platform> platformsInLevel = level.getPlatforms();
		std::vector<BreakPlatform> breakPlatformsInLevel = level.getBreakPlatforms();


		while (window.isOpen() && !level.isComplete(breakPlatformsInLevel)) {

			frame++;

			// Updates the score
			currentScorePrompt.setString("Score: " + to_string(currentScore));

			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
					pauseScreen(window, restartState);
				if (event.type == Event::KeyReleased && event.key.code == Keyboard::W)
					player.setWHeld(false);
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::R) {
					restartState = true;
				}
			}

			// If the player pressed R
			if (restartState) {
				restartState = false;
				levelNumber--;
				break;
			}

			game.update(player);
			game.collision(player, platformsInLevel);
			game.collision(player, breakPlatformsInLevel);
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel, Color::Black, currentScorePrompt);

			// If the player falls off the map they die
			if (player.isOutside())
				deathPrompt(window);

			// Decreases the score
			if (frame % 60 == 0) {
				frame = 0;
				if (currentScore > 0)
					currentScore--;
			}
		}
		
		// If the user completes the level
		if (level.isComplete(breakPlatformsInLevel)) {
			totalScore += currentScore;
			currentScore = 99;
		}
		else if (currentScore > 11)
			currentScore -= 10;

		// Transition between next level or restart
		fade(window, levelNumber, totalScore);
	}
	return 0;
};