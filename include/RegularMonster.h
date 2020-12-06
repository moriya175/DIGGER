#pragma once
#include "Monster.h"
class RegularMonster :public Monster
{
public:
	RegularMonster() = default;
	RegularMonster(sf::Vector2f location, double hight, double width);
	virtual ~RegularMonster() = default;
	virtual void move(sf::Time deltaTime)override;
protected:
};