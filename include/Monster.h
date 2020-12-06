#pragma once
#include "DinamikObject.h"
class Monster :public DinamikObject
{
public:
	Monster() = default;
	Monster(sf::Vector2f location, double hight, double width);
	virtual void move(sf::Time deltaTime) = 0;
	//sf::FloatRect getRectangleOfSpriteMonster();
	virtual ~Monster() = default;
	//virtual void colide(Monster& monster) override;
	//virtual void colide(Digger& digger) override;
protected:

};

