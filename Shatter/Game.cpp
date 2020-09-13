#include "Game.h"
#include<iostream>

void Game::update(Player& player) {

	//Keybinds
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


	//Gravity
	if (!player.getJump() && player.getYPos() <= player.getJumpHeight()) //if in the air & have reached peak jump height
		player.setYSpeed(10); 

	else if (player.getJump())
		player.setYSpeed(10);

	if (player.getYSpeed() == 10)
		player.setJump(false);

	//Changing the player's position by it's move speed
	player.move((float) player.getXSpeed(), (float) player.getYSpeed());
	player.setXSpeed(0);
}

void Game::draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms) {
	//Clearing Window
	window.clear(Color::Black);

	//Drawing platforms
	for (size_t i = 0; i < platforms.size(); i++) {
		window.draw(platforms[i].getShape());
	}
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		window.draw(breakPlatforms[i].getShape());
	}

	//Drawing player
	window.draw(player.getSprite());

	//Updating screen
	window.display();
}

void Game::collision(Player& player, std::vector<Platform>& platforms) {
	for (size_t i = 0; i < platforms.size(); i++) {
		Platform platform = platforms[i];
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) { //if player is touching a platform
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight() / 2 - 3) {
				std::cout << "top\n";
				player.setYPos((float) (platform.getYPos() - (player.getTexture().getSize().y) - 0.5));
				player.setJump(true);
				player.setYSpeed(0);
				player.setPlatformId(platform.getPlatformId());
			}
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 - 3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos((float) (platform.getYPos() + (platform.getHeight()) + 0.5));
				player.setYSpeed(10);
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos((float) (platform.getXPos() - (player.getTexture().getSize().x) - 0.4));
				player.setXSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout << "right\n";
				player.setXPos((float) (platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}
		}
	}
}

void Game::collision(Player& player, std::vector<BreakPlatform>& breakPlatforms) {
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		BreakPlatform platform = breakPlatforms[i];
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) {
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight() / 2 - 3) {
				player.setYPos((float) (platform.getYPos() - (player.getTexture().getSize().y) - 0.5));
				player.setJump(true);
				player.setYSpeed(0);

				if (platform.getHealth() == 0 && platform.getTimeOnLastTouch() + 2 <= std::time(nullptr)) {
					breakPlatforms[i].remove();
				}
				else if (platform.getHealth() == 1 && !platform.getIsTouched() && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].setTimeOnLastTouch(std::time(nullptr));
					breakPlatforms[i].touched();
					player.setPlatformId(platform.getPlatformId());
					}
				else if (!platform.getIsTouched() && platform.getHealth() > 1 && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].setIsTouched(true);
					breakPlatforms[i].touched();
					player.setPlatformId(platform.getPlatformId());
				}
			}
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 - 3 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				std::cout << "bot\n";
				player.setYPos((float) (platform.getYPos() + (platform.getHeight()) + 0.5));
			}
			else if (player.getXPos() <= platform.getXPos()) {
				std::cout << "left\n";
				player.setXPos((float) (platform.getXPos() - player.getTexture().getSize().x - 0.4));
				player.setXSpeed(0);
			}
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				std::cout << "right\n";
				player.setXPos((float) (platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}
		}
		else {
			breakPlatforms[i].setIsTouched(false);
			if (platform.getHealth() == 0 && platform.getTimeOnLastTouch() + 1 <= std::time(nullptr)) {
				breakPlatforms[i].remove();
			}
		}
	}
}
