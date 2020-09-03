#pragma once
#include"Player.h"
#include"Platform.h"
#include "BreakPlatform.h"


class Game
{
public:
	void update(Player& player);
	void draw(RenderWindow& window, Player& player, std::vector<Platform>& platforms, std::vector<BreakPlatform>& breakPlatforms, sf::Text pog);
	void collision(Player& player, std::vector<Platform>& platform);
	void collision(Player& player, std::vector<BreakPlatform>& breakPlatforms);
};

