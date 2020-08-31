#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Platform.h"
#include "Player.h"
#include "Game.h"
#include "BreakPlatform.h"
#include "Level.h"

using namespace sf;

int main() {

	RenderWindow window(VideoMode(1024, 576), "Shatter");
	window.setFramerateLimit(60);
	int time = 0;
	int frame = 0;
	Game game;

	for (int levelNumber = 1; levelNumber < 10; levelNumber++) {

		std::cout << "Level number: " << levelNumber << "\n";
		Player player(400, 0, 1);
		Level level(levelNumber);
		std::vector<Platform> platformsInLevel = level.getPlatforms();
		std::vector<BreakPlatform> breakPlatformsInLevel = level.getBreakPlatforms();


		while (window.isOpen() && !level.isComplete(breakPlatformsInLevel)) {
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
					window.close();
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
				}
			}

			game.update(player);
			game.collision(player, platformsInLevel);
			game.collision(player, breakPlatformsInLevel);
			level.isComplete(breakPlatformsInLevel);
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel);

			time += frame / 60;
			if (frame == 60) {
				frame = 0;
				//std::cout << time << "\n";
			}
			frame++;
		}
	}
	return 0;
};