#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "BreakPlatform.h"
#include "Platform.h"
#include "Processes.h"

class Level
{	// Level stays the same, only changes when a new level object is created
	int level;
	Vector2f startPosition;

	// List of platforms in the level
	std::vector<Platform> platformsInLevel;
	std::vector<BreakPlatform> breakPlatformsInLevel;

private:
	// Helpers to generate level from file
	void setStartingPosition(std::string line);
	void createPlatform(std::string line);
	void createLevelFromFile(int level);

public:
	// Builds the inputed level
	Level(int l);

	// Checks if all the destoryable platform are gone
	bool isComplete(std::vector<BreakPlatform>& breakPlatforms);

	// Gets the level number
	int getLevelNumber();

	// Gets the list of platform objects from the level object
	Vector2f getStartPosition();
	std::vector<Platform> getPlatforms();
	std::vector<BreakPlatform> getBreakPlatforms();
};

