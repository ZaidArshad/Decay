#include "Game.h"
#include<iostream>

void Game::update(Player& player) {
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.setXSpeed(10);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.setXSpeed(-10);
	}

	if (Keyboard::isKeyPressed(Keyboard::W) && player.getJump()) {
		player.setJump(false);
		player.setYSpeed(-10);
		player.setJumpHeight();
	}

	if (!player.getJump() && player.getYPos() <= player.getJumpHeight()) {  //if in the air & have reached peak jump height
		player.setYSpeed(10); 
	}
	else if (player.getJump()) {
		player.setYSpeed(10);
	}

	player.move((float) player.getXSpeed(), (float) player.getYSpeed());
	player.setXSpeed(0);
}

void Game::draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms) {
	window.clear(Color::Red);
	for (size_t i = 0; i < platforms.size(); i++) {
		window.draw(platforms[i].getShape());
	}
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		window.draw(breakPlatforms[i].getShape());
	}
	window.draw(player.getSprite());
	window.display();
}



void Game::collision(Player& player, std::vector<Platform>& platforms) {
	for (size_t i = 0; i < platforms.size(); i++) {
		Platform platform = platforms[i];
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) { //if player is touching a platform
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight() / 2 - 3) {
				std::cout << "top\n";
				player.setYPos(platform.getYPos() - (player.getTexture().getSize().y) - 0.5);
				player.setJump(true);
				player.setYSpeed(0);
			}
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 - 3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos(platform.getYPos() + (platform.getHeight()) + 0.5);
				player.setYSpeed(10);
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos(platform.getXPos() - (player.getTexture().getSize().x) - 0.4);
				player.setXSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout << "right\n";
				player.setXPos(platform.getXPos() + platform.getWidth() + 0.5);
				player.setXSpeed(0);
			}
		}
	}
}

void Game::collision(Player& player, std::vector<BreakPlatform>& breakPlatforms) {
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		BreakPlatform platform = breakPlatforms[i];
		std::cout << breakPlatforms[i].getIsTouched() << "\n";
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) { //if player is touching a platform
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight() / 2 - 3) {
				player.setYPos(platform.getYPos() - (player.getTexture().getSize().y) - 0.5);
				player.setJump(true);
				player.setYSpeed(0);
				if (!breakPlatforms[i].getIsTouched()) {
					breakPlatforms[i].setIsTouched(true);
					breakPlatforms[i].touched();
				}
			}
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 - 3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos(platform.getYPos() + (platform.getHeight()) + 0.5);
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos(platform.getXPos() - (player.getTexture().getSize().x) - 0.4);
				player.setXSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout << "right\n";
				player.setXPos(platform.getXPos() + platform.getWidth() + 0.5);
				player.setXSpeed(0);
			}
		}
		else {
			breakPlatforms[i].setIsTouched(false);
		}
	}
}