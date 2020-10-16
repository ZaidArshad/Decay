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
	Level(int l);
	bool isComplete(std::vector<BreakPlatform>& breakPlatforms);
	std::vector<Platform> getPlatforms();
	std::vector<BreakPlatform> getBreakPlatforms();
};

