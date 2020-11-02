#pragma once
#include <iostream>
#include "BreakPlatform.h"
#include "Platform.h"
#include "Processes.h"

class Level
{
	int level;
	std::vector<Platform> platformsInLevel;
	std::vector<BreakPlatform> breakPlatformsInLevel;

public:
	// Builds the inputed level
	Level(int l);
	// Checks if all the destoryable platform are gone
	bool isComplete(std::vector<BreakPlatform>& breakPlatforms);

	// Gets the list of platform objects from the level object
	std::vector<Platform> getPlatforms();
	std::vector<BreakPlatform> getBreakPlatforms();
};

