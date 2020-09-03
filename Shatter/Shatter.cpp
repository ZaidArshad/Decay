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


		Prompt title(200,200,"arial.ttf",50,"Shatter",sf::Color::White);
		Font ka1Font = title.getFont();


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

			if (player.isOutside()) {
				levelNumber--;
				break;
			}

			game.update(player);
			game.collision(player, platformsInLevel);
			game.collision(player, breakPlatformsInLevel);
			level.isComplete(breakPlatformsInLevel);
			game.draw(window, player, platformsInLevel, breakPlatformsInLevel, title.getText());

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