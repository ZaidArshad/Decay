#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include <iostream>

using namespace sf;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int MIDDLE_OF_SCREEN_X = SCREEN_WIDTH / 2;
const int MIDDLE_OF_SCREEN_Y = SCREEN_HEIGHT / 2;

const Vector2f startPositions[10] = {
	// Level 1
	Vector2f(100, MIDDLE_OF_SCREEN_Y - 200),
	// Level 2
	Vector2f(100, MIDDLE_OF_SCREEN_Y - 100),
	// Level 3
	Vector2f(500,0),
	// Level 4
	Vector2f(MIDDLE_OF_SCREEN_X-25, 50),
	// Level 5
	Vector2f(0,0),
	// Level 6
	Vector2f(0,0),
	// Level 7
	Vector2f(0,0),
	// Level 8
	Vector2f(0,0),
	// Level 9
	Vector2f(0,0),
	// Level 10
	Vector2f(0,0),
};

Font loadFont(std::string fontFileName);
void titleScreen(RenderWindow &window);
Color colorShifter(Color currentColor);
void pauseScreen(RenderWindow &window, bool &restartState);