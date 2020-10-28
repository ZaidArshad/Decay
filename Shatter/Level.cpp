#include "Level.h"

Level::Level(int l) {
	level = l;
	
	switch(level) {

	// Level 1
	case 1: {
		Platform platform(1000, 20, 0, 780);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(1, 100, 20, 190, 630);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(3, 100, 20, 350, 540);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(3, 100, 20, 560, 480);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 350, 350);
		breakPlatformsInLevel.push_back(breaker4);
		break;
	}
	// Level 2
	case 2: {
		Platform platform(1000, 20, 0, 780);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(1, 100, 20, 580, 660);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(2, 100, 20, 430, 570);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(3, 100, 20, 300, 490);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(1, 100, 20, 620, 490);
		breakPlatformsInLevel.push_back(breaker4);
		break;
	}
	// Level 3
	case 3: {
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
	// Level 4
	case 4: {
		Platform platform1(100, 20, 500, 100);
		platformsInLevel.push_back(platform1);
		//Platform platform2(100, 20, 850, MIDDLE_OF_SCREEN_Y + 150);
		//platformsInLevel.push_back(platform2);

		BreakPlatform breaker1(2, 100, 20, 350, 200);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(1, 100, 20, 100, MIDDLE_OF_SCREEN_Y);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(2, 100, 20, 200, MIDDLE_OF_SCREEN_Y+100);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 500, MIDDLE_OF_SCREEN_Y+260);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(3, 100, 20, 700, MIDDLE_OF_SCREEN_Y + 150);
		breakPlatformsInLevel.push_back(breaker5);
		break;
	}
	// Level 5
	case 5: {
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
	// Level 6
	case 6: {
		Platform platform(1000, 20, 0, 780);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(1, 100, 20, 860, 650);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(1, 100, 20, 700, 500);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 100, 20, 530, 420);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 670, 300);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(1, 100, 20, 380, 320);
		breakPlatformsInLevel.push_back(breaker5);
		BreakPlatform breaker6(1, 100, 20, 280, 200);
		breakPlatformsInLevel.push_back(breaker6);
		BreakPlatform breaker7(3, 100, 20, 300, 390);
		breakPlatformsInLevel.push_back(breaker7);
		BreakPlatform breaker8(2, 100, 20, 200, 490);
		breakPlatformsInLevel.push_back(breaker8);
		break;
	}
	// Level 7
	case 7: {
		Platform platform(1000, 20, 0, 780);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(2, 100, 20, 690, 650);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(6, 100, 20, 460, 540);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 100, 20, 240, 480);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 420, 400);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(1, 100, 20, 670, 430);
		breakPlatformsInLevel.push_back(breaker5);
		break;
	}
	// Level 8
	case 8: {
		Platform platform(100, 20, 720, 640);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(1, 100, 20, 420, 640);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(5, 100, 20, 160, 640);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 100, 20, 550, 510);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(1, 100, 20, 270, 510);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(1, 100, 20, 30, 510);
		breakPlatformsInLevel.push_back(breaker5);
		BreakPlatform breaker6(1, 100, 20, 700, 400);
		breakPlatformsInLevel.push_back(breaker6);
		BreakPlatform breaker7(1, 100, 20, 410, 400);
		breakPlatformsInLevel.push_back(breaker7);
		BreakPlatform breaker8(1, 100, 20, 160, 400);
		breakPlatformsInLevel.push_back(breaker8);
		BreakPlatform breaker9(1, 100, 20, 550, 280);
		breakPlatformsInLevel.push_back(breaker9);
		BreakPlatform breaker10(1, 100, 20, 270, 280);
		breakPlatformsInLevel.push_back(breaker10);
		break;
	}
	// Level 9
	case 9: {
		Platform platform(100, 20, 410, 440);
		platformsInLevel.push_back(platform);

		BreakPlatform breaker1(2, 100, 20, 450, 770);
		breakPlatformsInLevel.push_back(breaker1);
		BreakPlatform breaker2(4, 100, 20, 590, 570);
		breakPlatformsInLevel.push_back(breaker2);
		BreakPlatform breaker3(1, 100, 20, 730, 670);
		breakPlatformsInLevel.push_back(breaker3);
		BreakPlatform breaker4(2, 100, 20, 760, 490);
		breakPlatformsInLevel.push_back(breaker4);
		BreakPlatform breaker5(1, 100, 20, 620, 400);
		breakPlatformsInLevel.push_back(breaker5);
		BreakPlatform breaker6(1, 100, 20, 800, 250);
		breakPlatformsInLevel.push_back(breaker6);
		BreakPlatform breaker7(1, 100, 20, 580, 170);
		breakPlatformsInLevel.push_back(breaker7);
		BreakPlatform breaker8(1, 100, 20, 390, 260);
		breakPlatformsInLevel.push_back(breaker8);
		BreakPlatform breaker9(1, 100, 20, 210, 160);
		breakPlatformsInLevel.push_back(breaker9);
		BreakPlatform breaker10(1, 100, 20, 110, 270);
		breakPlatformsInLevel.push_back(breaker10);
		BreakPlatform breaker11(1, 100, 20, 10, 160);
		breakPlatformsInLevel.push_back(breaker11);
		BreakPlatform breaker12(2, 100, 20, 30, 430);
		breakPlatformsInLevel.push_back(breaker12);
		BreakPlatform breaker13(1, 100, 20, 190, 570);
		breakPlatformsInLevel.push_back(breaker13);
		BreakPlatform breaker14(1, 100, 20, 30, 680);
		breakPlatformsInLevel.push_back(breaker14);
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
