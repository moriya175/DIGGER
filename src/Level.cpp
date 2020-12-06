#include "..\include\Level.h"
#include <iostream>
#include <SFML/Audio.hpp>
//-------------------------------------------------------
//בנאי של שלב האחאי לקרוא לבנאי של הלוח לצורך בניתו
Level::Level(Digger &digger, const std::string& levelfile,int numOfLevel): m_board((*this),  digger, levelfile),m_stageNumber(numOfLevel)
{}
//-------------------------------------------------------
//דואג להרוס את ווקטור המפלצות
Level::~Level()
{
	for (auto mptr : m_monster)
		delete mptr;
}
//-------------------------------------------------------
//מקבל מהלוח זמן מוגבל לשלב
void Level::setStage(int limitTime)
{
	m_limitTime = limitTime;
}
//-------------------------------------------------------
//הכנסה לווקטור של המפלצות בהגרלה לסוגן
void Level::insertMonster(sf::Vector2f location, double hight, double width,Digger& digger)
{
int num = rand() % 3;
	if (num == 0)
		m_monster.push_back(new RegularMonster(location, hight, width));
	else
		m_monster.push_back(new SmartMonster(location, hight, width, digger,m_board));
}
//-------------------------------------------------------
//ציור שלב 
void Level::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
  for (auto monster : m_monster)
	    monster->draw(window);
}
//-------------------------------------------------------
//פונקציה לניהול השלב
bool Level::startLevel(Digger& digger, sf::RenderWindow& window, bool& restart)
{
	restart = false;
	Resources::getinstance().m_tuneGame.play();
	while ((!digger.getNumOfDiamond()==0))
	{
		window.clear();	
		move(digger);
		collision(digger);
		draw(window);
		m_info.informationDisplay(window, digger.getStone(), digger.getScore(), digger.getLives(), m_stageNumber, (digger.getaxtraTime() + m_limitTime) - int(m_clockLevel.getElapsedTime().asSeconds()));
		digger.draw(window);
		window.display();
		mangeEvent(digger, window);
		if (digger.getLives() < 0)
		{
			Resources::getinstance().m_tuneGame.stop();
			return false;
		}
		if (endTimeOfLevel(digger) || digger.getStone()==0)
		{
			digger.reduseLives();
			restart = true;
			return true;
		}
	}
	Resources::getinstance().m_tuneGame.stop();
	return true;
}
//-------------------------------------------------------
//פונקציה לניהול אירועים 
void Level::mangeEvent(Digger& digger, sf::RenderWindow& window)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
		case sf::Event::KeyPressed:
			digger.setDirection(event.key.code);
		default:
			break;
		}
}
//-------------------------------------------------------
//מחזירה בחיוב אם תם הזמן לשלב
bool Level::endTimeOfLevel(Digger& digger)
{
	return!(((digger.getaxtraTime()+m_limitTime) - int(m_clockLevel.getElapsedTime().asSeconds())) >= 0);
}
//-------------------------------------------------------
//פונקצית תזוזה שאחראית לקרוא לתזוזת השחקן והמפלצת
void Level::move(Digger& digger)
{
	auto deltatime = m_clockOfmoving.restart();
	for (auto monster : m_monster)
		monster->move(deltatime);
	digger.move(deltatime);
}
//-------------------------------------------------------
//פונקציה שמנהלת התנגשויות
void Level::collision(Digger& digger)
{
	auto cell = sf::Vector2f();
	cell = digger.getCell();
	if (cell != sf::Vector2f(-1, -1) && cell.y >=0&& cell.x >= 0 && cell.y < m_board.getRows() && cell.x < m_board.getCols()&& !m_board.isEmpty(cell))
	{
			m_board.getCell(cell)->colide(digger);
			if (m_board.getCell(cell)->checkEarse())
				m_board.deletCell(cell);
	}
	for (auto monsptr : m_monster)
	{
		cell = monsptr->getCell();
		if (cell != sf::Vector2f(-1, -1) && cell.y >= 0 && cell.x >= 0 && cell.y < m_board.getRows()  && cell.x < m_board.getCols() && !m_board.isEmpty(cell))
				m_board.getCell(cell)->colide(*monsptr);
	}
	for (auto monster : m_monster)
	{
		if (digger.isCollideMonster(*monster))
			for (auto monster : m_monster)
				monster->resetPosition();
	}
		
}

