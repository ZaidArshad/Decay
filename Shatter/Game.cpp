#include "Game.h"
#include<iostream>

void Game::update(Player& player) {

	// Keybinds
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.setXSpeed(10);
		player.animateRolling("right");
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.setXSpeed(-10);
		player.animateRolling("left");
	}
	else {
		player.animateRolling("still");
	}

	if (Keyboard::isKeyPressed(Keyboard::W) && player.getJump() && !player.getWHeld()) {
		player.setWHeld(true);
		player.setJump(false);
		player.setYSpeed(-10);
		player.setJumpHeight();
	}


	// Gravity
	if (!player.getJump() && player.getYPos() <= player.getJumpHeight()) //if in the air & have reached peak jump height
		player.setYSpeed(10);

	else if (player.getJump())
		player.setYSpeed(10);

	if (player.getYSpeed() == 10)
		player.setJump(false);

	// Changing the player's position by it's move speed
	player.move((float) player.getXSpeed(), (float) player.getYSpeed());
	player.setXSpeed(0);

	//Test
	//std::cout << "Update: " << player.getYPos() << "\n";
}

void Game::draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms) {
	// Clearing Window
	window.clear(Color::Black);

	// Drawing platforms
	for (size_t i = 0; i < platforms.size(); i++) {
		window.draw(platforms[i].getShape());
	}
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		window.draw(breakPlatforms[i].getShape());
	}

	// Drawing player
	window.draw(player.getSprite());

	//Test
	//std::cout << "Draw: " << player.getYPos() << "\n";

	// Updating screen
	window.display();
}

void Game::collision(Player& player, std::vector<Platform>& platforms) {
	for (size_t i = 0; i < platforms.size(); i++) {
		Platform platform = platforms[i];
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) { //if player is touching a platform

			// Top of the platform
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos()  && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight()) {
				player.setYPos((float)(platform.getYPos() - (player.getTexture().getSize().y)));
				player.setJump(true);
				player.setYSpeed(0);
				player.setPlatformId(platform.getPlatformId());
			}
			// Bot of the platform
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight() / 2 && player.getYPos() <= platform.getYPos() + platform.getHeight()) {
				player.setYPos((float)(platform.getYPos() + (platform.getHeight()) + 0.5));
				player.setYSpeed(10);
			}
			// Left of the platform
			else if (player.getXPos() <= platform.getXPos()) {
				player.setXPos((float)(platform.getXPos() - (player.getTexture().getSize().x) - 0.4));
				player.setXSpeed(0);
			}
			// Right of the platform
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {
				player.setXPos((float)(platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}
		}
	}
}

void Game::collision(Player& player, std::vector<BreakPlatform>& breakPlatforms) {
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		BreakPlatform platform = breakPlatforms[i];

		// If the player is touching the platform
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) {

			// Top of the platform
			if (player.getYPos() + player.getTexture().getSize().y >= platform.getYPos() && player.getYPos() + player.getTexture().getSize().y <= platform.getYPos() + platform.getHeight()+9) {
				player.setYPos((float)(platform.getYPos() - (player.getTexture().getSize().y)));
				player.setJump(true);
				player.setYSpeed(0);

				// If the platform is touched at 0 health the glory time has elasped
				if (platform.getHealth() == 0 && breakPlatforms[i].getTimeOnLastTouch() + 2 <= std::time(nullptr)) {
					breakPlatforms[i].remove();
				}

				// If the platform is at 1 hp and is not touched and is a different platform from last jump
				else if (platform.getHealth() == 1 && !platform.getIsTouched() && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].setTimeOnLastTouch(std::time(nullptr));
					breakPlatforms[i].touched();
					player.setPlatformId(platform.getPlatformId());
				}

				// If the platform is healthier than 1 hp andis a different platform from last jump
				else if (!platform.getIsTouched() && platform.getHealth() > 1 && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].setIsTouched(true);
					breakPlatforms[i].touched();
					player.setPlatformId(platform.getPlatformId());
				}
			}

			// Bottom of platform
			else if (player.getYPos() >= platform.getYPos() + platform.getHeight()  && player.getYPos() <= platform.getYPos() + platform.getHeight()) {

				std::cout << "bot\n";

				player.setYPos((float)(platform.getYPos() + platform.getHeight() + 0.5));
				player.setYSpeed(10);
			}
			// Left of platform
			else if (player.getXPos() <= platform.getXPos()) {

				std::cout << "left\n";

				player.setXPos((float)(platform.getXPos() - player.getTexture().getSize().x - 0.4));
				player.setXSpeed(0);
			}
			// Right of platform
			else if (player.getXPos() <= (platform.getXPos() + platform.getWidth())) {

				std::cout << "right\n";

				player.setXPos((float)(platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}
		}
		else {
			// When the platform is dead, remain alive for 2 seconds
			breakPlatforms[i].setIsTouched(false);
		}
		// Slowly remove the platform whe it's health is gone
		if (platform.getHealth() == 0 && platform.getHeight() > 1)
			breakPlatforms[i].setHeight(breakPlatforms[i].getHeight() - 0.25);

		// Remove the platform once it is small enough
		else if (platform.getHealth() == 0 && platform.getHeight() <= 1)
			breakPlatforms[i].remove();

	}
}
