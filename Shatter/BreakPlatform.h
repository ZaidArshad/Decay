#pragma once
#include "Platform.h"

class BreakPlatform : public Platform
{
	int health;
	bool isTouched = false;
	Color healthIndex[7] = {
		Color::Red,
		Color(255, 128, 0),
		Color::Yellow,
		Color::Green,
		Color::Blue,
		Color(75,0,130),
		Color(148,0,211)};
public:
	BreakPlatform(int healt, float  w, float  h, float  x, float y);
	void touched();
	bool getIsTouched();
	void setIsTouched(bool status);
	int getHealth();
};

