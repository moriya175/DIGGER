#pragma once
#include "Consts.h"
#include "Resources.h"
#include "Button.h"
#include "ExitGame.h"
#include "NewGame.h"
#include <SFML/Graphics.hpp>
using std::vector;
class Menu
{
public:
	Menu();
	void displaymenu(sf::RenderWindow& window, bool& startgame);
	~Menu();
protected:
	vector <Button*>m_button;
	sf::Sprite m_picture;
	void draw(sf::RenderWindow& window);
	void handleClick(const sf::Vector2f& location, bool& startgame, bool& buttonPressed);
	sf::Sprite& insertexture(sf::Texture* picture, double hight, double width);
};