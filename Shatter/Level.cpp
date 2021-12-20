#include "Level.h"

Level::Level(int l) {
	level = l;
	createLevelFromFile(level);

	//Setting ids for each platform to give them a unique identifier
	int id;

	// Setting ids for the breakable platforms
	for (int i = 0; i < breakPlatformsInLevel.size(); i++) {
		id = i + 1;
		breakPlatformsInLevel[i].setPlatformId(id);
	}
	// Setting ids for non breakable platforms
	for (int i = 0; i < platformsInLevel.size(); i++) {
		id = (i*-1) -1;
		platformsInLevel[i].setPlatformId(id);
	}
}

// Gets the start position of the level
Vector2f Level::getStartPosition() { return startPosition;}

// Gets the vectors of the platforms from the level
std::vector<Platform> Level::getPlatforms() { return platformsInLevel;  }
std::vector<BreakPlatform> Level::getBreakPlatforms() { return breakPlatformsInLevel; }

// Checks if the level is complete
bool Level::isComplete(std::vector<BreakPlatform> &breakPlatforms) {

	// Keeps track of how many platforms are in the level
	int platformsAlive = breakPlatforms.size();

	// Iterates through the platforms to check the health
	for (int i = 0; i < breakPlatforms.size(); i++) {

		// If the platform is *dead* reduce the count
		if (breakPlatforms[i].getHealth() == 0) {
			platformsAlive--;
		}
	}
	// If there are not platforms on the level
	if (platformsAlive == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Gets the starting position from given line from the file "levelX.txt"
void Level::setStartingPosition(std::string line) {
	std::string val = "";

	for (char c : line) {
		if (c == ' ') {
			startPosition.x = std::stoi(val);
			val = "";
		}
		else {
			val += c;
		}
	}
	startPosition.y = std::stoi(val);
}

// Creates a platform from a string of fields "health width height xPos yPos"
void Level::createPlatform(std::string line) {
	int platFields[5];
	int index = 0;
	std::string val = "";

	// Goes through the characters in the line and fills them out with values
	for (char c : line) {
		if (c == ' ') {
			platFields[index] = std::stoi(val);
			index++;
			val = "";
		}
		else {
			val += c;
		}
	}

	// Completes the last field
	platFields[index] = std::stoi(val);

	int health = platFields[0];
	int width = platFields[1];
	int height = platFields[2];
	int xPos = platFields[3];
	int yPos = platFields[4];

	// Debug
	//cout << health << " " << width << " " << height << " " << xPos << " " << yPos << std::endl;

	// If the platform has health make it a breakable platform, other wise make it a regular one
	if (health > 0) {
		breakPlatformsInLevel.push_back(BreakPlatform(health, width, height, xPos, yPos));
	}
	else {
		platformsInLevel.push_back(Platform(width, height, xPos, yPos));
	}
}

// Generates a list of platforms from "levelX.txt"
void Level::createLevelFromFile(int level) {
	std::string line;
	std::ifstream levelFile;
	bool hasStartingPos = false;
	std::string fileLocation = "levels/level" + std::to_string(level) + ".txt";
	levelFile.open(fileLocation);

	if (levelFile.is_open()) {
		while (std::getline(levelFile, line)) {
			if (!hasStartingPos) {
				setStartingPosition(line);
				hasStartingPos = true;
			}
			else createPlatform(line);
		}
	}
	else {
		breakPlatformsInLevel.push_back(BreakPlatform(8, 500, 25, 0, 400));
	}
}
