#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Digger.h"
class Game
{
public:
	Game() = default;
	~Game() = default;
	void startGame(sf::RenderWindow& window);
	void infoLosOrWin(sf::RenderWindow& window, const bool& passedGame);
protected:
	Digger m_digger;
};