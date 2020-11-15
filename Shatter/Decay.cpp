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


	for (int levelNumber = 1; levelNumber < 11; levelNumber++) {

		if (!window.isOpen())
			break;

		std::cout << "Level number: " << levelNumber << "\n";
		Player player(startPositions[levelNumber-1].x, startPositions[levelNumber-1].y, 1);
		Level level(levelNumber);
		std::vector<Platform> platformsInLevel = level.getPlatforms();
		std::vector<BreakPlatform> breakPlatformsInLevel = level.getBreakPlatforms();


		while (window.isOpen() && !level.isComplete(breakPlatformsInLevel)) {

			frame++;
			auto start = std::chrono::system_clock::now();


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
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel, Color::Black);

			// If the player falls off the map they die
			if (player.isOutside())
				deathPrompt(window);

			// Decreases the score
			if (frame % 60 == 0) {
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> elapsed_seconds = end - start;
				std::cout <<  frame/elapsed_seconds.count()/60 << " FPS\n";
				frame = 0;
				if (game.getLevelScore() > 0)
					game.setLevelScore(game.getLevelScore()-1);
			}
			
		}
		
		// If the user completes the level
		if (level.isComplete(breakPlatformsInLevel)) {
			game.addToTotalScore();
			game.setLevelScore(99);
		}
		else if (game.getLevelScore() > 11)
			game.setLevelScore(game.getLevelScore() - 10);

		// Transition between next level or restart
		fade(window, levelNumber, game.getTotalScore());
	}
	return 0;
};