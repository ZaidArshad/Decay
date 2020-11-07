#pragma once
#include"Player.h"
#include"Platform.h"
#include "BreakPlatform.h"
#include "Prompt.h"


class Game
{
	int totalScore = 0;
	int levelScore = 99;
	Prompt currentScorePrompt = Prompt(825, 50, "ka1.ttf", 40, "Score: 99", Color::White);

public:
	// Updates player position and controls gravity
	void update(Player& player);

	// Draws the player, platforms and breakplatforms onto the screen
	void draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms, Color c);

	// Detects the collision between the player and platforms
	void collision(Player& player, std::vector<Platform>& platform);
	void collision(Player& player, std::vector<BreakPlatform>& breakPlatforms);

	// Setting score attributes
	void addToTotalScore();
	void setLevelScore(int lScore);

	// Getting score attributes
	int getTotalScore();
	int getLevelScore();
	Prompt getPromptScore();
};

