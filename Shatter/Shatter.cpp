#include<iostream>
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include "Platform.h"
#include "Player.h"

using namespace sf;

void Update(Player &player);
void Draw(RenderWindow& window, Player &player, Platform &platform);

int main()
{
	sf::RenderWindow window(VideoMode(1024, 576), "Shatter");
	window.setFramerateLimit(60);

	Player player(0,0,1);


	Texture aTexture;
	if (!aTexture.loadFromFile("images/soupCan.png")) {
		std::cout << "Load failed\n";
		system("pause");
	}
	player.setTexture(aTexture);

	Platform platform(100, 25, 400, 300);

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

		Update(player);
		Draw(window, player, platform);
	}
	return 0;
};



void Update(Player &player) {
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.move(10, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.move(-10, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		player.move(0, 10);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		player.move(0, -10);
	}
}

void Draw(RenderWindow &window, Player &player, Platform &platform) {
	window.clear(Color::Red);
	window.draw(platform.getShape());
	window.draw(player.getSprite());
	window.display();
}
