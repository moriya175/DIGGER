#include "Digger.h"
#include "Monster.h"
//-------------------------------------------------------
//הבנאי של השחקן
Digger::Digger() :m_live(TOTALLIVE), m_score(0), m_time(0)
{
}
//-------------------------------------------------------
//מעדכן נתונים הפונקציה נקראת בקריאה מהקובץ
void Digger::setdata(sf::Vector2f location, double hight, double width)
{
	m_pictures.clear();
	insertToVector({ Resources::getinstance().getTexture(digger1),Resources::getinstance().getTexture(digger2),Resources::getinstance().getTexture(digger3)}, location, hight, width);
	m_statlocation = location;
	m_direction = { 0,0 };
	m_nextDirection = Spase;
}
//-------------------------------------------------------
//תזוזת השחקן
void Digger::move(sf::Time deltaTime)
{
	m_prevPosition = m_pictures[0].getPosition();
	moveSprite(deltaTime);
	//if (m_nextDirection==getDirection(m_direction))
	//transform(m_nextDirection);
}
//-------------------------------------------------------
//עדכון הכיוון הבא
void Digger::setDirection(sf::Keyboard::Key key)
{
	if (sf::Keyboard::Key::Space == key)
		m_nextDirection = Spase;
	else
	m_nextDirection = (convertKeyToDirection(key));
}
//-------------------------------------------------------
//מחזירה את מיקום השחקן
sf::Vector2f Digger::getPosition()const
{
	return (m_pictures[0].getPosition());
}
//-------------------------------------------------------
//מעדכן את מס היהלומים והאבנים בכל שלב
void Digger::setDiamondAndStone(int numOfDiamond,int numstone)
{
	m_numOfDiamnd= numOfDiamond;
	m_stone = numstone;
	m_time = 0;
}
//-------------------------------------------------------
//מחזיר את מס היהלומים שנותרו
int Digger::getNumOfDiamond() const
{
	return m_numOfDiamnd;
}
//-------------------------------------------------------
//מחזיר את הניקוד שנצבר
int Digger::getScore() const
{
	return m_score;
}
//-------------------------------------------------------
//מחזיר את מס החיים שנותר
int Digger::getLives() const
{
	return m_live;
}
//-------------------------------------------------------
//מחזיר את מס האבנים שנותר לאכול
int Digger::getStone() const
{
	return m_stone;
}
//-------------------------------------------------------
//מחזיר את תוספת הזמן
int Digger::getaxtraTime() const
{
	return m_time;
}
//-------------------------------------------------------
//פונקציה להמרה key 
Directions Digger::convertKeyToDirection(sf::Keyboard::Key key)
{
	return Directions(key-71);
}
//-------------------------------------------------------
//פונקציה שדואגת לסובב את תמונת השחקן ע"פ הכיוון
void Digger::transform(Directions direction)
{
	float angle = 0; auto factors = sf::Vector2f(1, 1);
	switch (direction)
	{
	case Directions::Left:
		angle = 0;
		factors = (m_direction == calculateDirection(Left)) ?
			sf::Vector2f(1, 1) : sf::Vector2f(-1, 1); break;
	case Directions::Right:
		angle = 0;
		factors = (m_direction == calculateDirection(Left)) ?
			sf::Vector2f(-1, 1) : sf::Vector2f(1, 1); break;
	case Directions::Down:
		angle = 90;
		factors = (m_direction == calculateDirection(Left)) ?
			sf::Vector2f(-1, 1) : sf::Vector2f(1, 1); break;
	case Directions::Up:
		angle = 270;
		factors = (m_direction  == calculateDirection(Left)) ?
			sf::Vector2f(-1, 1) : sf::Vector2f(1, 1); break;
	}
	for (auto& sprite : m_pictures)
	{
		sprite.setRotation(angle);
		sprite.scale(factors);
	}
}
//-------------------------------------------------------
//הורדת חיים
void Digger::reduseLives()
{
	m_live--;
}
//-------------------------------------------------------
//מודיע כמה אבנים נותרו
int Digger::getDiamondsLeft() const
{
	return m_numOfDiamnd;
}
//-------------------------------------------------------
//מוריד יהלומים
void Digger::setDiamond(int num)
{
	m_numOfDiamnd += num;
}
//-------------------------------------------------------
//תוספת ניקוד
void Digger::addScore(int score)
{
	m_score += score;

}
//-------------------------------------------------------
//תוספת אבנים 
void Digger::addStones()
{
	m_stone += 2;
}
//-------------------------------------------------------
//תוספת זמן
void Digger::addTime(int time)
{
	m_time += time;
}
//-------------------------------------------------------
//הפחתת אבנים
void Digger::reduseStone()
{
	m_stone--;
}
//-------------------------------------------------------
//טיפול בהתנגשות של שחקן עם מפלצת
bool Digger::isCollideMonster(Monster& monster)
{
	if (getRectangle().intersects(monster.getRectangle()))
	{
		if (getLives() != -1)
		{
			reduseLives();
			resetPosition();
			return true;
		}
	}
	return false;
}
