#pragma once
#include "DinamikObject.h"
class Monster;
class Digger :public DinamikObject
{
public:
	Digger();
	void setdata(sf::Vector2f location, double hight, double width);
    void move(sf::Time deltaTime);
	~Digger() = default;
	void setDirection(sf::Keyboard::Key key);
	sf::Vector2f getPosition()const;
	void setDiamondAndStone(int numOfDiamond, int numstone);
	int getNumOfDiamond()const;
	int getScore()const;
	int getLives()const;
	int getStone()const;
	int getaxtraTime()const;
	void reduseLives();
	int getDiamondsLeft() const;
	void setDiamond(int num);
	void addScore(int score);
	void addStones();
	void addTime(int time);
	void reduseStone();
	bool isCollideMonster(Monster& monster);
protected:
	int m_time;
	int m_numOfDiamnd;
	int m_score;
	int m_live;
	int m_stone;
	Directions convertKeyToDirection(sf::Keyboard::Key key);
	void transform(Directions direction);
	
};