#include "Monster.h"
//-------------------------------------------------------
//����� ������ �� ������ ���� ������
Monster::Monster(sf::Vector2f location, double hight, double width)
{
	insertToVector({Resources::getinstance().getTexture(monster1),Resources::getinstance().getTexture(monster2), Resources::getinstance().getTexture(monster3), Resources::getinstance().getTexture(monster4)}, location, hight, width);
	m_statlocation = location;
}
//-------------------------------------------------------
//����� �� ������ ����� ���� ������ ����� ��� �������
void Monster::move(sf::Time deltaTime)
{
	m_prevPosition = m_pictures[0].getPosition();
}
//-------------------------------------------------------


