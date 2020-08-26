#pragma once
#include"Player.h"
#include"Platform.h"

class Game
{
public:
	void update(Player& player);
	void draw(RenderWindow& window, Player& player, Platform& platform);
	void collision(Player& player, std::vector<Platform>& platform);
};

