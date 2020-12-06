#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
class Button
{
public:
	Button(sf::Texture* picture, double hight, double width, sf::Vector2f location);
	~Button()=default;
	void draw(sf::RenderWindow& window);
	bool checkPosition(const sf::Vector2f& location, const float width, const float height) const;
	virtual void handleClick(bool &startGame)=0;
protected:
	sf::Sprite m_sprite;
	sf::Sprite& insertexture(sf::Texture* picture, double hight, double width, sf::Vector2f location);
};