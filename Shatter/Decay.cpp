#pragma once
#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Platform.h"
#include "Player.h"
#include "Game.h"
#include "BreakPlatform.h"
#include "Level.h"
#include "Prompt.h"
#include "Processes.h"

using namespace sf;

int main() {
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "DECAY", sf::Style::Default | sf::Style::Close);


	bool restartState = false;
	window.setFramerateLimit(60);
	Game game;

	sf::Music music;
	music.setVolume(7);
	music.setLoop(true);
	if (music.openFromFile("sounds/space_fighter_loop.wav")) music.play();

	sf::SoundBuffer buffer;
	buffer.loadFromFile("sounds/speedup.wav");
	sf::Sound restartSound;
	restartSound.setVolume(25);
	restartSound.setBuffer(buffer);

	sf::SoundBuffer buffer2;
	buffer2.loadFromFile("sounds/slowdown.wav");
	sf::Sound dieSound;
	dieSound.setVolume(25);
	dieSound.setBuffer(buffer2);

	titleScreen(window);
	fade(window, 0, 0);
	int frame = 0;
	bool canPause = false;
	auto start = std::chrono::system_clock::now();
	

	for (int levelNumber = 1; levelNumber < 11; levelNumber++) {
		
		// Plays music if it is paused and stops all sounds effects
		if (music.getStatus() == music.Paused) music.play();
		restartSound.stop();
		dieSound.stop();

		if (!window.isOpen())
			break;

		std::cout << "Level number: " << levelNumber << "\n";
		Player player(startPositions[levelNumber-1].x, startPositions[levelNumber-1].y, 1);
		Level level(levelNumber);
		std::vector<Platform> platformsInLevel = level.getPlatforms();
		std::vector<BreakPlatform> breakPlatformsInLevel = level.getBreakPlatforms();


		while (window.isOpen() && !level.isComplete(breakPlatformsInLevel)) {
			
			if (frame == 1)
				start = std::chrono::system_clock::now();
			frame++;

			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::JoystickButtonReleased && event.joystickButton.button != Joystick::isButtonPressed(0, 7))
					canPause = true;
				if ((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || ((Joystick::isButtonPressed(0, 7) && canPause))) {
					pauseScreen(window, restartState);
					canPause = false;
				}
				if ((event.type == Event::KeyReleased && (event.key.code == Keyboard::W || event.key.code == Keyboard::Up)) ||event.type == Event::JoystickButtonReleased && event.joystickButton.button == Joystick::isButtonPressed(0,0))
					player.setWHeld(false);
				if ((event.type == Event::KeyPressed && event.key.code == Keyboard::R) || (Joystick::isButtonPressed(0, 5))) {
					restartState = true;
				}
			}

			// If the player pressed R
			if (restartState) {
				restartSound.play();
				restartState = false;
				levelNumber--;
				break;
			}

			game.update(player);
			game.collision(player, platformsInLevel);
			game.collision(player, breakPlatformsInLevel);
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel, Color::Black);

			// If the player falls off the map they die
			if (player.isOutside()) {
				dieSound.play();
				music.pause();
				deathPrompt(window);
			}

			// Decreases the score
			if (frame % 60 == 0) {
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> elapsed_seconds = end - start;
				std::cout <<  frame/elapsed_seconds.count() << " FPS\n";
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
		if (levelNumber < 10) {
			fade(window, levelNumber, game.getTotalScore());
		}

	}
	gameOverScreen(window, game.getTotalScore());
	return 0;
};