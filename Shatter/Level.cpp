#include "Level.h"

Level::Level(int l) {
	level = l;
	
	switch(level) {
	case 1: {
		Platform platform(100, 20, 50, MIDDLE_OF_SCREEN_Y);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(4, 100, 20, 250, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(3, 100, 20, 450, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(3, 100, 20, 650, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 850, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker4);
		break;
	}

	case 2: {
		Platform platform(100, 20, 50, MIDDLE_OF_SCREEN_Y);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(2, 100, 20, 250, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(3, 100, 20, 450, MIDDLE_OF_SCREEN_Y + 100);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 100, 20, 650, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(1, 100, 20, 850, MIDDLE_OF_SCREEN_Y - 100);
		breakPlatformsInLevel.push_back(breaker4);
		break;
	}

	case 3: {
		Platform platform1(100, 20, 500, 100);
		platformsInLevel.push_back(platform1);
		Platform platform2(100, 20, 850, MIDDLE_OF_SCREEN_Y + 150);
		platformsInLevel.push_back(platform2);

		BreakPlatform breaker1(2, 100, 20, 350, 200);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(1, 100, 20, 100, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(2, 100, 20, 200, MIDDLE_OF_SCREEN_Y+100);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 500, MIDDLE_OF_SCREEN_Y+150);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(3, 100, 20, 700, MIDDLE_OF_SCREEN_Y + 150);
		breakPlatformsInLevel.push_back(breaker5);
		break;
	}
	case 4: {
		Platform platform1(100, 20, MIDDLE_OF_SCREEN_X-50, 150);
		platformsInLevel.push_back(platform1);

		BreakPlatform breaker1(2, 100, 20, MIDDLE_OF_SCREEN_X-50, 400);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(1, 100, 20, MIDDLE_OF_SCREEN_X+150, MIDDLE_OF_SCREEN_Y+25);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 20, 20, 200, MIDDLE_OF_SCREEN_Y + 100);
		breakPlatformsInLevel.push_back(breaker3);
		break;
	}
	default: {
		Platform platform(100, 25, 400, 300);
		break; 
	}
	}

	//Setting ids for each platform
	int id;
	for (int i = 0; i < breakPlatformsInLevel.size(); i++) {
		id = i + 1;
		breakPlatformsInLevel[i].setPlatformId(id);
	}
	for (int i = 0; i < platformsInLevel.size(); i++) {
		id = (i*-1) -1;
		platformsInLevel[i].setPlatformId(id);
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
