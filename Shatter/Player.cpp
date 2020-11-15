#include "Player.h"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include<iostream>

using namespace sf;

// Regular constructor
Player::Player(float x, float y, float s) {
	scale = s;
	xPos = x;
	yPos = y;
	xSpeed = 0;
	ySpeed = 10;
	canJump = false; // Keeps track if the player can jump
	platformId = 0; // Keeps track of the platform the player last touched
	rollingSpriteId = 0; // Keeps track of the sprie it is on
	frame = 0; // Keeps track of the frame the sprite
	wHeld = false; // If the user is holding down the W key

	// Loads the sprite sheet of the can
	if (!playerTexture.loadFromFile("images/can.png")) {
		std::cout << "Load failed\n";
		system("pause");
	}

	// Sets the sprite to the player
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(xPos, yPos);
}

//------Setters------//
void Player::setScale(float s) {
	scale = s;
	playerSprite.setScale(scale, 1);
}
void Player::setXPos(float x) {
	xPos = x;
	playerSprite.setPosition(xPos, yPos);
}
void Player::setYPos(float  y) {
	yPos = y;
	playerSprite.setPosition(xPos, yPos);
}
void Player::setSprite(Sprite sprite) { playerSprite = sprite; }
void Player::setTexture(Texture &texture) {playerSprite.setTexture(texture);}
void Player::setXSpeed(int xVel) { xSpeed = xVel; }
void Player::setYSpeed(int yVel) { ySpeed = yVel; }
void Player::setJump(bool jumped) { canJump = jumped; }
void Player::setJumpHeight() { jumpHeight = yPos - 150; }
void Player::setPlatformId(int id) { platformId = id; }
void Player::setWHeld(bool state) { wHeld = state; }

//------Getters------//
float Player::getXPos() { return xPos; }
float Player::getYPos() { return yPos; }
float Player::getScale() { return scale; }
Texture Player::getTexture() { return playerTexture; }
Sprite Player::getSprite() { return playerSprite; }
int Player::getXSpeed() { return xSpeed; }
int Player::getYSpeed() { return ySpeed; }
bool Player::getJump() { return canJump; }
float Player::getJumpHeight() { return jumpHeight; }
int Player::getPlatformId() { return platformId; }

// Moves the player
void Player::move(float x, float y) {
	playerSprite.move(x, y);
	xPos += x;
	yPos += y;
}

// If the player is bellow the screen
bool Player::isOutside() {
	if (yPos > SCREEN_HEIGHT) { return true; }
	else { return false;  }
}

// Gets the status of the w key being held
bool Player::getWHeld() { return wHeld; }

// Animates the sprite of the player
void Player::animateRolling(String direction) {

	bool isRolling = true; // Keeps track of the of the state of the can
	frame += 1;

	// Can only change sprite every 4 frames or more
	if (frame > 4) {

		// Loads the sprie sprite sheet
		if (!canSpriteSheet.loadFromFile("images/canRollingSpriteSheet.png")) {
			std::cout << "Load failed\n";
			system("pause");
		}

		// If the player is moving left
		if (direction == "left") {
			rollingSpriteId--;

			// If spritesheet wants to left on the first frame set it to the last frame
			if (rollingSpriteId < 0)
				rollingSpriteId = 3;
		}

		// If the player is moving right
		else if (direction == "right") {
			rollingSpriteId++;
			if (rollingSpriteId > 3)
				rollingSpriteId = 0;
		}

		// If the can is not rolling
		else {
			rollingSpriteId = 0;
			isRolling = false;
		}

		// If the can is rolling
		if (isRolling) {
			// Gets the frame from the sprite sheet
			IntRect frameSize(50 * rollingSpriteId, 0, 50, 50);
			Sprite canSpriteRolling(canSpriteSheet, frameSize);
			playerSprite = canSpriteRolling;
			playerSprite.setPosition(xPos, yPos);
		}

		// If the sprite is not being animated set it to its default position
		else {
			Sprite sprite;
			sprite.setTexture(playerTexture);
			playerSprite = sprite;
			playerSprite.setPosition(xPos, yPos);
		}

		// Resets the frame count
		frame = 0;
	}

}


