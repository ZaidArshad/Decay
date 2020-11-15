#include "Game.h"
#include "Prompt.h"
#include<iostream>

void Game::update(Player& player) {

	// KEYBINDS //

	// D pressed -> Rolling right
	if (Keyboard::isKeyPressed(Keyboard::D)) { 
		player.setXSpeed(10);
		player.animateRolling("right");
	}
	// A pressed -> Rolling left
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.setXSpeed(-10);
		player.animateRolling("left");
	}
	// Nothing pressed -> Staying still
	else {
		player.animateRolling("still");
	}
	// First W press -> Jumping 
	if (Keyboard::isKeyPressed(Keyboard::W) && player.getJump() && !player.getWHeld()) {
		player.setWHeld(true); // Keeps track if the playing is holding w
		player.setJump(false); // Keeps track if the user has jumped of a platform
		player.setYSpeed(-10);
		player.setJumpHeight();
	}


	// GRAVITY //
	if (!player.getJump() && player.getYPos() <= player.getJumpHeight()) //if in the air & have reached peak jump height
		player.setYSpeed(10);

	// When the player is not jumping, fall
	else if (player.getJump())
		player.setYSpeed(10);

	// When the player is falling
	if (player.getYSpeed() == 10)
		player.setJump(false); // Keep track that the player is not jumping

	// Changing the player's position by it's move speed
	player.move((float) player.getXSpeed(), (float) player.getYSpeed());
	player.setXSpeed(0); // Resets the speed afters it's moved
}

void Game::draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms, Color c) {
	// Clearing Window
	window.clear(c);

	// Drawing platforms
	for (size_t i = 0; i < platforms.size(); i++) {
		window.draw(platforms[i].getShape());
	}
	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		window.draw(breakPlatforms[i].getShape());
	}

	// Draws the score
	currentScorePrompt.textColorShifter();
	window.draw(currentScorePrompt.getText());

	// Drawing player
	window.draw(player.getSprite());

	// Updating screen
	window.display();
}

void Game::collision(Player& player, std::vector<Platform>& platforms) {

	// Player cords on the extended sides from the x and y cordinates
	float playerBot = player.getYPos() + player.getTexture().getSize().y;
	float playerRight = player.getXPos() + player.getTexture().getSize().x;

	for (size_t i = 0; i < platforms.size(); i++) {
		Platform platform = platforms[i];

		// Platform cords on the extended sides from the x and y cordinates
		float platformBot = platform.getYPos() + platform.getHeight();
		float platformRight = platform.getXPos() + platform.getWidth();

		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) { //if player is touching a platform

			// Left of platform
			if (player.getXPos() < platform.getXPos() && playerRight <= platform.getXPos() + 10 && (player.getYPos() <= platform.getYPos() || playerBot >= platformBot)) {
				player.setXPos((float)(platform.getXPos() - player.getTexture().getSize().x));
				player.setXSpeed(0);
			}
			// Right of platform
			else if (playerRight > platformRight && player.getXPos() >= platformRight - 10 && (player.getYPos() <= platform.getYPos() || playerBot >= platformBot)) {
				player.setXPos((float)(platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}
			// Top of the platform 
			else if (player.getYPos() < platform.getYPos() && playerBot >= platform.getYPos()) {
				player.setYPos((float)(platform.getYPos() - (player.getTexture().getSize().y)));
				player.setJump(true);
				player.setYSpeed(0);
				player.setPlatformId(platform.getPlatformId());
			}
			// Bottom of platform
			else if (playerBot > platformBot && player.getYPos() <= platformBot) {
				player.setYPos((float)(platform.getYPos() + platform.getHeight())); // Sets the player to the bottom of the platform
				player.setYSpeed(10);
			}
		}
	}
}

void Game::collision(Player& player, std::vector<BreakPlatform>& breakPlatforms) {

	// Player cords on the extended sides from the x and y cordinates
	float playerBot = player.getYPos() + player.getTexture().getSize().y;
	float playerRight = player.getXPos() + player.getTexture().getSize().x;

	for (size_t i = 0; i < breakPlatforms.size(); i++) {
		BreakPlatform platform = breakPlatforms[i];

		// Platform cords on the extended sides from the x and y cordinates
		float platformBot = platform.getYPos() + platform.getHeight();
		float platformRight = platform.getXPos() + platform.getWidth();

		// If the player is touching the platform
		if (player.getSprite().getGlobalBounds().intersects(platform.getShape().getGlobalBounds())) {

			// Left of platform
			if (player.getXPos() < platform.getXPos() && playerRight <= platform.getXPos()+10 && (player.getYPos() <= platform.getYPos() || playerBot >= platformBot)) {
				player.setXPos((float)(platform.getXPos() - player.getTexture().getSize().x));
				player.setXSpeed(0);
			}
			// Right of platform
			else if (playerRight > platformRight && player.getXPos() >= platformRight-10 && (player.getYPos() <= platform.getYPos() || playerBot >= platformBot)) {
				player.setXPos((float)(platform.getXPos() + platform.getWidth() + 0.5));
				player.setXSpeed(0);
			}

			// Top of the platform
			else if (player.getYPos() < platform.getYPos() && playerBot >= platform.getYPos()) {
				player.setYPos((float)(platform.getYPos() - (player.getTexture().getSize().y))); // Sets the player to the top of the platform
				player.setJump(true); // Emable the player to jump
				player.setYSpeed(0);


				// If the platform is at 1 hp and is not touched and is a different platform from last jump
				if (platform.getHealth() == 1 && !platform.getIsTouched() && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].touched(); // Decrease the health of the platform
					player.setPlatformId(platform.getPlatformId()); // Keeps track of the platform the player last touched
				}

				// If the platform is healthier than 1 hp andis a different platform from last jump
				else if (!platform.getIsTouched() && platform.getHealth() > 1 && player.getPlatformId() != platform.getPlatformId()) {
					breakPlatforms[i].setIsTouched(true); // Tells the game that the platform is touched
					breakPlatforms[i].touched(); // Decrease the health
					player.setPlatformId(platform.getPlatformId()); // Keeps track of the platform the player last touched
				}
			}
			// Bottom of platform
			else if (playerBot > platformBot && player.getYPos() <= platformBot) {
				player.setYPos((float) (platform.getYPos() + platform.getHeight())); // Sets the player to the bottom of the platform
				player.setYSpeed(10);
			}
		}

		// If the player is not touching the platform, tell the game that it is not
		else 
			breakPlatforms[i].setIsTouched(false);

		// Slowly remove the platform whem it's health is gone
		if (platform.getHealth() == 0 && platform.getHeight() > 1)
			breakPlatforms[i].setHeight(breakPlatforms[i].getHeight() - 0.25);

		// Remove the platform once it is small enough
		else if (platform.getHealth() == 0 && platform.getHeight() <= 1)
			breakPlatforms[i].remove();

	}
}

// Setting score attributes
void Game::addToTotalScore() { totalScore += levelScore;  }
void Game::setLevelScore(int lScore) { 
	levelScore = lScore;
	currentScorePrompt.setString("Score: " + to_string(levelScore));
}

// Getting score attributes
int Game::getTotalScore() { return totalScore; }
int Game::getLevelScore() { return levelScore; }
Prompt Game::getPromptScore() { return currentScorePrompt;  }