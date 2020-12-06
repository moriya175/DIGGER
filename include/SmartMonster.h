#pragma once
#include "Monster.h"
#include "Digger.h"
#include <cmath> 
class Board;
class SmartMonster :public Monster
{
public:
	SmartMonster(sf::Vector2f location, double hight, double width,Digger& digger, Board& board);
	~SmartMonster() = default;
	virtual void move(sf::Time deltaTime)override;
protected:
	Digger& m_digger;
	Board& m_board;
	float distanseFromPlayer(sf::Vector2f possibleDestigntion);
};