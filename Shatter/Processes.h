#pragma once
#include"SFML\System.hpp"
#include"SFML\Graphics.hpp"
#include <iostream>

using namespace sf;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 576;
const int MIDDLE_OF_SCREEN_X = SCREEN_WIDTH / 2;
const int MIDDLE_OF_SCREEN_Y = SCREEN_HEIGHT / 2;

Font loadFont(std::string fontFileName);
void titleScreen(RenderWindow &window);
Color colorShifter(Color currentColor);
void pauseScreen(RenderWindow &window);