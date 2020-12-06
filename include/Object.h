#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Consts.h"
class Object
{
public:
	Object() = default;
	~Object() = default;
//	virtual void colide(Digger& digeer) = 0;
	//virtual void colide(Monster& monster) = 0;
protected:
	sf::Sprite updateSprite(sf::Texture* picture, sf::Vector2f location, double hight, double width);
};