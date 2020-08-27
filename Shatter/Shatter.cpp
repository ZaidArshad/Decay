#include <iostream>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "Platform.h"
#include "Player.h"
#include "Game.h"

using namespace sf;


int main()
{
	sf::RenderWindow window(VideoMode(1024, 576), "Shatter");
	window.setFramerateLimit(60);

	Game game;
	Player player(400,0,1);
	Platform platform(100, 25, 400, 300);
	Platform platform2(100, 25, 500, 250);

	std::vector<Platform> platformsInLevel;
	platformsInLevel.push_back(platform);
	platformsInLevel.push_back(platform2);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}
		game.update(player);
		game.collision(player, platformsInLevel);
		game.draw(window, player, platformsInLevel);
	}
	return 0;
};