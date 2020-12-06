#include "..\include\Game.h"
#include <SFML/Audio.hpp>
//-------------------------------------------------------
//פונקציה שמנהלת ריצת משחק
void Game::startGame(sf::RenderWindow& window)
{
	string status;
	bool restart = false,passedlevel=false;
	auto filelevel = std::string("level1.txt");
	int i = 1;
	while (std::ifstream(filelevel))
	{
		Level level(m_digger, filelevel,i);
		passedlevel=level.startLevel(m_digger, window, restart);
		if (!passedlevel)
			break;
		if (!restart)
			i++;
		filelevel = std::string("level") + std::to_string(i) + std::string(".txt");
	}
	infoLosOrWin(window, passedlevel);
}
//-------------------------------------------------------
//פונקציה שמודיעה על הפסד או ניצחון
void Game::infoLosOrWin(sf::RenderWindow& window,const bool &passedGame)
{
	sf::Clock info;
	sf::Sprite sprite;
	if (passedGame)
	{
	  sf::Sprite sprite1(*Resources::getinstance().getTexture(won));
	  sprite = sprite1;
	  Resources::getinstance().m_won.play();
	}
	else
	{
		sf::Sprite sprite1(*Resources::getinstance().getTexture(gameover));
		sprite = sprite1;
		Resources::getinstance().m_gameover.play();
	}
	while (7 - int(info.getElapsedTime().asSeconds()) >= 0)
	{
		window.draw(sprite);
		window.display();
		window.clear();
	}
	Resources::getinstance().m_won.stop();
	Resources::getinstance().m_gameover.stop();
}