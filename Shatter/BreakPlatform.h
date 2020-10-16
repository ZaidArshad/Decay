#pragma once
#include "Platform.h"
#include <ctime>
#include <iostream>
#include <chrono>

class BreakPlatform : public Platform
{
	// Health attribute
	int health;

	// Boolean data
	bool isTouched = false;

	// Time data (initialized with time on creation)
	std::time_t timeOnLastTouch = std::time(nullptr);

	// Color index for changing platform color relative to health
	Color healthIndex[8] = {
		Color::White,
		Color::Red,
		Color(255, 128, 0),
		Color::Yellow,
		Color::Green,
		Color::Blue,
		Color(75,0,130),
		Color(148,0,211)};



public:
	//------Constructors------//
	BreakPlatform(int hp, float  w, float  h, float  x, float y);

	//------Setter Methods------//
	void setIsTouched(bool status);
	void setHealth(int hp);
	void setTimeOnLastTouch(std::time_t t);


	//------Getter Methods------//
	bool getIsTouched();
	int getHealth();
	std::time_t getTimeOnLastTouch();

	// Decreases the health of the platform and changes color
	void touched();

	// Removes the platfrom from the screen but is still alive in scope
	void remove();
};

