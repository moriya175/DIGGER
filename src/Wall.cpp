#include "Wall.h"
//-------------------------------------------------------

//���� �� ���
Wall::Wall(sf::Vector2f location, double hight, double width) : StaticObject(wall, location, hight, width)
{}
//-------------------------------------------------------
//����� �������� �� ���� �� ���
void Wall::colide(Digger& digeer)
{
	digeer.updateToPrevPosition();
	 m_toEarse=false;
}
//-------------------------------------------------------
//����� �������� �� ����� �� ���
void Wall::colide(Monster& monster)
{
	monster.updateToPrevPosition();
}

