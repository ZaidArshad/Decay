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

	Platform platform(100, 25, 400, 300);
	platform.getShape().setOrigin(platform.getWidth() / 2, platform.getHeight() / 2);

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

		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) {

			if (player.getYPos()+player.getTexture().getSize().y  >= platform.getYPos() && player.getYPos()+ player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight()/2-3) {
				std::cout << "top\n";
				player.setYPos(platform.getYPos() - (player.getTexture().getSize().y) - 0.5);
			}
			else if (player.getYPos() >= platform.getYPos()+platform.getHeight()/2-3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos(platform.getYPos() + (platform.getHeight()) + 0.5);
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos(platform.getXPos() - (player.getTexture().getSize().x)-0.4);
				player.setSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout<< "right\n";
				player.setXPos(platform.getXPos() + platform.getWidth()+0.5);
				player.setSpeed(0);
			}

		}
		else {
			//std::cout << "\n";
			player.setSpeed(10);
		}

		Draw(window, player, platform);
	}
	return 0;
};



void Update(Player &player) {
	int speed = player.getSpeed();
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.move(speed, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.move(-speed, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		player.move(0, speed);
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) {
		player.move(0, -speed);
	}
}

void Draw(RenderWindow &window, Player &player, Platform &platform) {
	window.clear(Color::Red);
	window.draw(platform.getShape());
	window.draw(player.getSprite());
	window.display();
}
