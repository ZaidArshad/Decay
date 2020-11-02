#pragma once
#include"Player.h"
#include"Platform.h"
#include "BreakPlatform.h"
#include "Prompt.h"


class Game
{
public:
	// Updates player position and controls gravity
	void update(Player& player);

	// Draws the player, platforms and breakplatforms onto the screen
	void draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms, Color c, Prompt &currentScore);

	// Detects the collision between the player and platforms
	void collision(Player& player, std::vector<Platform>& platform);
	void collision(Player& player, std::vector<BreakPlatform>& breakPlatforms);
};

