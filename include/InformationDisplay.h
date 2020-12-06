#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
class InformationDisplay 
{
public:
	InformationDisplay();
	void informationDisplay(sf::RenderWindow& window,const int stone,const int score, const int live, const int level,const int time);
	~InformationDisplay()=default;
protected:
	sf::Text m_printLives;
	sf::Text m_printScore;
	sf::Text m_printLevel;
	sf::Text m_printStone;
	bool m_flickerTime;
	void clockDisplay(sf::RenderWindow& window, const int time, sf::Text test);
	void setText(sf::Text& text ,const sf::Vector2f &location, const int& size);
};