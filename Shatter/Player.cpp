#include "Player.h"
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include<iostream>

using namespace sf;

Player::Player(float x, float y, float s) {
	scale = s;
	xPos = x;
	yPos = y;

	if (!playerTexture.loadFromFile("images/soupCan.png")) {
		std::cout << "Load failed\n";
		system("pause");
	}
	playerSprite.setTexture(playerTexture);
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

float Player::getXPos() { return xPos; }
float Player::getYPos() { return yPos; }
float Player::getScale() { return scale; }
Texture Player::getTexture() { return playerTexture; }
Sprite Player::getSprite() { return playerSprite; }

void Player::move(float x, float y) {
	playerSprite.move(x, y);
	xPos += x;
	yPos += y;
}

