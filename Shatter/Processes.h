#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include "Prompt.h"
#include <iostream>

using namespace sf;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int MIDDLE_OF_SCREEN_X = SCREEN_WIDTH / 2;
const int MIDDLE_OF_SCREEN_Y = SCREEN_HEIGHT / 2;

const Vector2f startPositions[10] = {
	// Level 1
	Vector2f(100, 700),
	// Level 2
	Vector2f(100, 700),
	// Level 3
	Vector2f(100, MIDDLE_OF_SCREEN_Y - 100),
	// Level 4
	Vector2f(500,0),
	// Level 5
	Vector2f(MIDDLE_OF_SCREEN_X - 25, 50),
	// Level 6
	Vector2f(100, 700),
	// Level 7
	Vector2f(600, 700),
	// Level 8
	Vector2f(720, 485),
	// Level 9
	Vector2f(420, 390),
	// Level 10
	Vector2f(0,0),
};

Font loadFont(std::string fontFileName);
void titleScreen(RenderWindow &window);
Color colorShifter(Color currentColor);
void pauseScreen(RenderWindow &window, bool &restartState);
void fade(RenderWindow& window, int level, int score);
void deathPrompt(RenderWindow& window);