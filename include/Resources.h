#include <SFML/Audio.hpp>
#pragma once
#include "Consts.h"
#include <SFML/Graphics.hpp>
#include <vector>
class Resources
{
public:
	sf::Texture* getTexture(const int index);//מחזירה מצביע לתמונהשנמצאת באינדקס שהתקבל
	std::vector<sf::Texture>m_picture;//וקטור של תמונות
	static Resources& getinstance();
	sf::Font m_font;
	sf::Music m_tuneGame;
	sf::Music m_gameover;
	sf::Music m_won;
protected:
	Resources();//בנאי של לינקר שקורא את התמונות
	void insertPicture();
};


