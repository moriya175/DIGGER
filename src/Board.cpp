#include "..\include\Board.h"
#include "Level.h"
#include <iostream>
//-------------------------------------------------------
Board::Board(Level& stage, Digger& digger,const std::string& levelfile):m_input(levelfile)//הבנאי של הלוח 
{
    backgroundUpdate();
    readFile(stage, digger);
}
//-------------------------------------------------------
Board::~Board()//להרוס את הלוח
{
    for (auto sptr : m_obj)
        delete sptr;
    m_input.close();
}
//-------------------------------------------------------
void Board::readFile(Level& stage, Digger& digger)//פונקציה לקריאה מהקובץ
{
	int  numstone,counterDiamond=0, limitTime;
    m_input >> m_row >> m_col >> numstone >> limitTime;
    std::string line;
    std::getline(m_input, line);
    double hight = (WINDOWSIDE -INFOHIGHT) / m_row , width = WINDOWSIDE / m_col;
    stage.setStage(limitTime);
   char c;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			c = m_input.get();
            insertObject(c, hight, width, i,j,stage, counterDiamond,digger);
		}
       std::getline(m_input, line);
	}
    digger.setDiamondAndStone(counterDiamond, numstone);
}
//-------------------------------------------------------
//עדכון הרקע של הלוח
void Board::backgroundUpdate()
{
    m_backgroundpicture = sf::Sprite(*(Resources::getinstance().getTexture(background)));
    auto texSize = (Resources::getinstance().getTexture(background))->getSize();
    auto newTexSize = sf::Vector2u(WINDOWSIDE, WINDOWSIDE);
    auto scaleX = newTexSize.x * 1.00f / texSize.x;
    auto scaleY = newTexSize.y * 1.00f / texSize.y;
    m_backgroundpicture.scale(scaleX, scaleY);
}
//-------------------------------------------------------
//הכנסה לווקטור עבור כל אובייקט שהתגלה בלוח
void Board::insertObject(char c,double hight, double width, int i,int j, Level& stage,int& counterDiamond ,Digger& digger)
{
    sf::Vector2f location(sf::Vector2f(float((j * width) + (width / 2)), float((i * hight) + (hight / 2)+ INFOHIGHT)));
    switch (c)//הכנסה לווקטור של התווים
    {
    case DIAMOND:
        m_obj.push_back(new Diamond(location, hight, width));
        counterDiamond++;break;   
    case WALL:
        m_obj.push_back(new Wall(location, hight, width));break;
    case STONE:
        m_obj.push_back(new Stone(location, hight, width));break;
    case DIGGER:
        digger.setdata(location, hight, width);
        m_obj.push_back(nullptr);break;
   case GIFT:
       addGift(location, hight, width);break;
    case MONSTER:
        stage.insertMonster(location, hight, width, digger);
        m_obj.push_back(nullptr);break;
    default:
        m_obj.push_back( nullptr);break;
    }
}
//-------------------------------------------------------
//הוספת מתנות בהגרלה 
void Board::addGift(sf::Vector2f location, double hight, double width)
{
    int num = rand() % 3;
    if (num == 0)
        m_obj.push_back(new GiftTime(location, hight, width));
    else if (num == 1)
        m_obj.push_back(new GiftStone(location, hight, width));
    else if (num == 2)
        m_obj.push_back(new GiftScore(location, hight, width));
}
//-------------------------------------------------------
//ציור הלוח
void Board::draw(sf::RenderWindow& window)
{
    window.draw(m_backgroundpicture);
    for (int i = 0; i < m_obj.size(); i++)
        if(m_obj[i]!=nullptr)
        m_obj[i]->draw(window);
}
//-------------------------------------------------------
//בדיקה אם המקום  ריק
bool Board::isEmpty(sf::Vector2f cell)
{
    if (m_obj[(cell.y * m_col) + cell.x] == nullptr)
        return true;
    return false;
}
//-------------------------------------------------------
//פונקציה שמחזירה אובייקט מהווקטור
StaticObject* Board::getCell(sf::Vector2f cell)
{
    return m_obj[(cell.y * m_col) + cell.x];
}
//-------------------------------------------------------
//מחיקת תא
void Board::deletCell(sf::Vector2f location)
{
    delete m_obj[(location.y * m_col) + location.x];
    m_obj[(location.y*m_col)+ location.x] = nullptr;
}
//-------------------------------------------------------
//פונקציה לקבלת מס השורות
int Board::getRows() const
{
    return m_row;
}
//-------------------------------------------------------
//פונקציה לקבלת מס העמודות
int Board::getCols() const
{
    return m_col;
}
//-------------------------------------------------------
bool Board::isWall(const sf::Vector2f& location) const
{
    if(location.y >= 0 && location.x >= 0 && location.y < getRows() && location.x < getCols() )
    return (typeid(Wall).name() == typeid(*m_obj[(location.y * m_col) + location.x]).name());
    return false;
}

bool Board::isStone(const sf::Vector2f& location) const
{
    if (location.y >= 0 && location.x >= 0 && location.y < getRows() && location.x < getCols())
    return(typeid(Stone).name() == typeid(*m_obj[(location.y * m_col) + location.x]).name());
    return false;
}

