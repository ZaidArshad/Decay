#include "Level.h"

Level::Level(int l) {
	level = l;
	
	switch(level) {
	case 1: {
		Platform platform(100, 25, 400, 300);
		Platform platform2(100, 25, 500, 250);
		platformsInLevel.push_back(platform);
		platformsInLevel.push_back(platform2);

		BreakPlatform breaker(7, 100, 25, 600, 400);
		breakPlatformsInLevel.push_back(breaker);
		BreakPlatform breaker2(7, 100, 25, 600, 500);
		breakPlatformsInLevel.push_back(breaker2);
		break;
	}

	case 2: {
		BreakPlatform breaker(7, 100, 25, 600, 400);
		breakPlatformsInLevel.push_back(breaker);
		BreakPlatform breaker2(7, 100, 25, 400, 400);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(7, 100, 25, 200, 400);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(7, 100, 25, 0, 400);
		breakPlatformsInLevel.push_back(breaker4);
	}
	default: {
		Platform platform(100, 25, 400, 300);
		break; 
	}
	}
}

std::vector<Platform> Level::getPlatforms() { return platformsInLevel;  }
std::vector<BreakPlatform> Level::getBreakPlatforms() { return breakPlatformsInLevel; }


bool Level::isComplete(std::vector<BreakPlatform> &breakPlatforms) {
	int platformsAlive = breakPlatforms.size();
	for (int i = 0; i < breakPlatforms.size(); i++) {
		if (breakPlatforms[i].getHealth() == 0) {
			platformsAlive--;
		}
	}
	if (platformsAlive == 0) {
		std::cout << "you winnnn\n";
		return true;
	}
	else {
		return false;
	}
}