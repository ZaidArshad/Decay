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
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Shatter");
	bool restartState = false;
	window.setFramerateLimit(60);
	Game game;
	titleScreen(window);
	fade(window, 0);
	Prompt background(0, 0, "bulkypix.ttf", 0, "", Color::White);

	for (int levelNumber = 1; levelNumber < 10; levelNumber++) {
		std::cout << "Level number: " << levelNumber << "\n";
		Player player(startPositions[levelNumber-1].x, startPositions[levelNumber-1].y, 1);
		Level level(levelNumber);
		std::vector<Platform> platformsInLevel = level.getPlatforms();
		std::vector<BreakPlatform> breakPlatformsInLevel = level.getBreakPlatforms();


		while (window.isOpen() && !level.isComplete(breakPlatformsInLevel)) {
			background.textColorShifter();

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
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel, background.getColor());

			// If the player falls off the map they die
			if (player.isOutside())
				deathPrompt(window);


		}
		// Transition between next level or restart
		fade(window, levelNumber);
	}
	return 0;
};