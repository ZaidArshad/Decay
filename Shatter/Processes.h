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

Font loadFont(std::string fontFileName);
void titleScreen(RenderWindow &window);
Color colorShifter(Color currentColor);
void pauseScreen(RenderWindow &window, bool &restartState);
void fade(RenderWindow& window, int level, int score);
void deathPrompt(RenderWindow& window);
void gameOverScreen(RenderWindow& window, int score);