#include "Game.h"
#include<iostream>

void Game::update(Player& player) {
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

void Game::draw(RenderWindow& window, Player& player, Platform& platform) {
	window.clear(Color::Red);
	window.draw(platform.getShape());
	window.draw(player.getSprite());
	window.display();
}

void Game::collision(Player& player, std::vector<Platform>& platforms) {
	for (int i = 0; i < platforms.size(); i++) {
		Platform platform = platforms[i];

		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) {

			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight() / 2 - 3) {
				std::cout << "top\n";
				player.setYPos(platform.getYPos() - (player.getTexture().getSize().y) - 0.5);
			}
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 - 3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos(platform.getYPos() + (platform.getHeight()) + 0.5);
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos(platform.getXPos() - (player.getTexture().getSize().x) - 0.4);
				player.setSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout << "right\n";
				player.setXPos(platform.getXPos() + platform.getWidth() + 0.5);
				player.setSpeed(0);
			}
		}
		else {
			player.setSpeed(10);
		}
	}
}