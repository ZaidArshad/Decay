#include "Player.h"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include<iostream>

using namespace sf;

Player::Player(float x, float y, float s) {
	scale = s;
	xPos = x;
	yPos = y;
	xSpeed = 0;
	ySpeed = 10;
	canJump = false;
	jumpHeight = 0;

	if (!playerTexture.loadFromFile("images/soupCan.png")) {
		std::cout << "Load failed\n";
		system("pause");
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(xPos, yPos);
	playerSprite.setScale(scale, 1);
}
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
void Player::setTexture(Texture &texture) {playerSprite.setTexture(texture);}
void Player::setXSpeed(int xVel) { xSpeed = xVel; }
void Player::setYSpeed(int yVel) { ySpeed = yVel; }
void Player::setJump(bool jumped) { canJump = jumped; }
void Player::setJumpHeight() { jumpHeight = yPos - 100; }

float Player::getXPos() { return xPos; }
float Player::getYPos() { return yPos; }
float Player::getScale() { return scale; }
Texture Player::getTexture() { return playerTexture; }
Sprite Player::getSprite() { return playerSprite; }
int Player::getXSpeed() { return xSpeed; }
int Player::getYSpeed() { return ySpeed; }
bool Player::getJump() { return canJump; }
float Player::getJumpHeight() { return jumpHeight; }

void Player::move(float x, float y) {
	playerSprite.move(x, y);
	xPos += x;
	yPos += y;
}

bool Player::isOutside() {
	if (yPos > 576 || yPos < 0) { return true; }
	else { return false;  }
}



