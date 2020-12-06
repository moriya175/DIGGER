#pragma once
#include "StaticObject.h"
#include <vector>
#include <fstream>
#include "Consts.h"
#include "Resources.h"
#include "Diamond.h"
#include "Wall.h"
#include "Stone.h"
#include "Gift.h"
#include "GiftScore.h"
#include "GiftStone.h"
#include "GiftTime.h"
#include "Digger.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;
using std::ifstream;
using std::vector;
class Level;
class Board
{
public:
	Board(Level& stage, Digger& digger,const std::string& levelfile);
	Board()=default;
	~Board();
	void draw(sf::RenderWindow& window);
	bool isEmpty(sf::Vector2f cell);
	StaticObject* getCell(sf::Vector2f cell);
	void deletCell(sf::Vector2f location);
	int getRows()const;
	int getCols()const;
	bool isWall(const sf::Vector2f& location) const;
	bool isStone(const sf::Vector2f& location) const;
protected:
	ifstream m_input;
	int m_row;
	int m_col;
	vector <StaticObject*>m_obj;
	void backgroundUpdate();
	void readFile(Level& stage, Digger& digger);
	void insertObject(char c, double hight, double width, int i, int j, Level& stage, int& counterDiamond, Digger& digger);
	void addGift(sf::Vector2f location, double hight, double width);
	sf::Sprite m_backgroundpicture;
};