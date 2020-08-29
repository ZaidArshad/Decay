#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Platform.h"
#include "Player.h"
#include "Game.h"
#include "BreakPlatform.h"
#include <algorithm>

using namespace sf;


int main() {

	sf::RenderWindow window(VideoMode(1024, 576), "Shatter");
	window.setFramerateLimit(60);
	Game game;

	Player player(400,0,1);
	Platform platform(100, 25, 400, 300);
	Platform platform2(100, 25, 500, 250);
	BreakPlatform breaker(7,100,25,600,400);
	BreakPlatform blankBreaker(7, 100, 25, -500, -500);

	std::vector<Platform> platformsInLevel;
	platformsInLevel.push_back(platform);
	platformsInLevel.push_back(platform2);
	std::vector<BreakPlatform> breakPlatformsInLevel;
	breakPlatformsInLevel.push_back(blankBreaker);
	breakPlatformsInLevel.push_back(breaker);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
				breaker.touched();
			}
		}

		game.update(player);
		game.collision(player, platformsInLevel);
		game.collision(player, breakPlatformsInLevel);
		game.draw(window, player, platformsInLevel, breakPlatformsInLevel);
	}
	return 0;
};