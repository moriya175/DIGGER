#pragma once
#include "StaticObject.h"
#include "Digger.h"
class Wall :public StaticObject
{
public:
	Wall(sf::Vector2f location, double hight, double width);
	~Wall() = default;
	virtual void colide(Digger& digeer)override;
	virtual void colide(Monster& monster) override;
protected:
};