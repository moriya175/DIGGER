#pragma once
#include "Object.h"
#include <vector>
#include "Consts.h"
class DinamikObject :public Object
{
public:
	DinamikObject()=default;
	void draw(sf::RenderWindow& window);
	void limitBoard();
	void updateToPrevPosition();
	~DinamikObject() = default;
	void resetPosition();
	sf::FloatRect getRectangle();
	sf::Vector2f getCell()const;
protected:
	bool checkNotOnExis();
	sf::Vector2f calculateDirection(Directions direction);
	bool checkDirection();
	sf::Vector2f topLeft();
	Directions getDirection(sf::Vector2f direction) const;
	Directions  m_nextDirection;
	sf::Vector2f m_statlocation;           
	std::vector<sf::Sprite>m_pictures;
	void moveSprite(sf::Time deltaTime);
	int m_index;
	int m_numOfstep= MAXSTEP;
	sf::Vector2f m_direction = {0,0};
	sf::Vector2f m_prevPosition;
	void insertToVector(std::vector<sf::Texture*> texture, sf::Vector2f location, double hight, double width);
};
