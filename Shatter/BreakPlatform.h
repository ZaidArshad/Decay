#pragma once
#include "Platform.h"
#include <ctime>
#include <iostream>

class BreakPlatform : public Platform
{
	int health;
	bool isTouched = false;
	Color healthIndex[8] = {
		Color::White,
		Color::Red,
		Color(255, 128, 0),
		Color::Yellow,
		Color::Green,
		Color::Blue,
		Color(75,0,130),
		Color(148,0,211)};
	std::time_t timeOnLastTouch;
public:
	BreakPlatform(int healt, float  w, float  h, float  x, float y);
	void touched();
	bool getIsTouched();
	void setIsTouched(bool status);
	void setHealth(int h);
	void remove();
	int getHealth();
	std::time_t getTimeOnLastTouch();
	void setTimeOnLastTouch(std::time_t t);
};

