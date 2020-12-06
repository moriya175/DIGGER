#pragma once
#include <vector>
#include "RegularMonster.h"
#include "SmartMonster.h"
#include "Digger.h"
#include "Monster.h"
#include "Resources.h"
#include "Board.h"
#include "Digger.h"
#include "InformationDisplay.h"

class Level
{
public:
	Level( Digger& digger, const std::string& levelfile,int numOfLevel);
	~Level();
	void setStage(int limitTime);
	void insertMonster(sf::Vector2f location, double hight, double width,Digger& digger);
	void draw(sf::RenderWindow& window);
	bool startLevel(Digger& digger, sf::RenderWindow& window,bool &restart);
protected:
	void mangeEvent(Digger& digger, sf::RenderWindow& window);
	InformationDisplay m_info;
	vector <Monster*>m_monster;
	Board m_board;
	bool endTimeOfLevel(Digger& digger);
	int m_stageNumber;
	int m_limitTime;
	sf::Clock m_clockLevel;
	sf::Clock m_clockOfmoving;
	void move(Digger& digger);
	void collision(Digger& digger);
};