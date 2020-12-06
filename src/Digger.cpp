#include "Digger.h"
#include "Monster.h"
//-------------------------------------------------------
//����� �� �����
Digger::Digger() :m_live(TOTALLIVE), m_score(0), m_time(0)
{
}
//-------------------------------------------------------
//����� ������ �������� ����� ������ ������
void Digger::setdata(sf::Vector2f location, double hight, double width)
{
	m_pictures.clear();
	insertToVector({ Resources::getinstance().getTexture(digger1),Resources::getinstance().getTexture(digger2),Resources::getinstance().getTexture(digger3)}, location, hight, width);
	m_statlocation = location;
	m_direction = { 0,0 };
	m_nextDirection = Spase;
}
//-------------------------------------------------------
//����� �����
void Digger::move(sf::Time deltaTime)
{
	m_prevPosition = m_pictures[0].getPosition();
	moveSprite(deltaTime);
	//if (m_nextDirection==getDirection(m_direction))
	//transform(m_nextDirection);
}
//-------------------------------------------------------
//����� ������ ���
void Digger::setDirection(sf::Keyboard::Key key)
{
	if (sf::Keyboard::Key::Space == key)
		m_nextDirection = Spase;
	else
	m_nextDirection = (convertKeyToDirection(key));
}
//-------------------------------------------------------
//������ �� ����� �����
sf::Vector2f Digger::getPosition()const
{
	return (m_pictures[0].getPosition());
}
//-------------------------------------------------------
//����� �� �� �������� ������� ��� ���
void Digger::setDiamondAndStone(int numOfDiamond,int numstone)
{
	m_numOfDiamnd= numOfDiamond;
	m_stone = numstone;
	m_time = 0;
}
//-------------------------------------------------------
//����� �� �� �������� ������
int Digger::getNumOfDiamond() const
{
	return m_numOfDiamnd;
}
//-------------------------------------------------------
//����� �� ������ �����
int Digger::getScore() const
{
	return m_score;
}
//-------------------------------------------------------
//����� �� �� ����� �����
int Digger::getLives() const
{
	return m_live;
}
//-------------------------------------------------------
//����� �� �� ������ ����� �����
int Digger::getStone() const
{
	return m_stone;
}
//-------------------------------------------------------
//����� �� ����� ����
int Digger::getaxtraTime() const
{
	return m_time;
}
//-------------------------------------------------------
//������� ����� key 
Directions Digger::convertKeyToDirection(sf::Keyboard::Key key)
{
	return Directions(key-71);
}
//-------------------------------------------------------
//������� ������ ����� �� ����� ����� �"� ������
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
//����� ����
void Digger::reduseLives()
{
	m_live--;
}
//-------------------------------------------------------
//����� ��� ����� �����
int Digger::getDiamondsLeft() const
{
	return m_numOfDiamnd;
}
//-------------------------------------------------------
//����� �������
void Digger::setDiamond(int num)
{
	m_numOfDiamnd += num;
}
//-------------------------------------------------------
//����� �����
void Digger::addScore(int score)
{
	m_score += score;

}
//-------------------------------------------------------
//����� ����� 
void Digger::addStones()
{
	m_stone += 2;
}
//-------------------------------------------------------
//����� ���
void Digger::addTime(int time)
{
	m_time += time;
}
//-------------------------------------------------------
//����� �����
void Digger::reduseStone()
{
	m_stone--;
}
//-------------------------------------------------------
//����� �������� �� ���� �� �����
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
