#pragma once
#include "Object.h"
#include "Digger.h"
#include "Monster.h"
class StaticObject:public Object
{
public:
	StaticObject() = default;
	StaticObject(NamesOfPicture index, sf::Vector2f location, double hight, double width);
	virtual ~StaticObject() = default;
	void draw(sf::RenderWindow& window);
	bool checkEarse();
	//virtual void colide(Monster& monster) override;
	//virtual void colide(Digger& digger) override
	virtual void colide(Digger& digeer) = 0;
	virtual void colide(Monster& monster) = 0;
protected:
	sf::Sprite m_picture;
	bool m_toEarse;
};