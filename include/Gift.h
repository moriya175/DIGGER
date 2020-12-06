#pragma once
#include "StaticObject.h"
class Gift :public StaticObject
{
public:
	Gift()=default;
	Gift(NamesOfPicture index, sf::Vector2f location, double hight, double width);
	~Gift() = default;
	virtual void colide(Digger& digeer) = 0;
	virtual void colide(Monster& monster) = 0;
protected:
};