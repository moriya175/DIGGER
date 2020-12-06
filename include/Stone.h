#pragma once
#include "StaticObject.h"
#include "Digger.h"
class Stone :public StaticObject
{
public:
	Stone(sf::Vector2f location, double hight, double width);
	~Stone() = default;
	virtual void colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:
};