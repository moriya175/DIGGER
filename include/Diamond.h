#pragma once
#include "StaticObject.h"
class Diamond :public StaticObject
{
public:
	Diamond(sf::Vector2f location, double hight, double width);
	~Diamond() = default;
	virtual void colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:
};