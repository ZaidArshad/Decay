#pragma once
#include"Player.h"
#include"Platform.h"

class Game
{
public:
	void Update(Player& player);
	void Draw(RenderWindow& window, Player& player, Platform& platform);
	void Collision(Player& player, Platform& platform);
};

