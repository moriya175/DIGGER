#include "Diamond.h"
//-------------------------------------------------------
//����� �� �����
Diamond::Diamond(sf::Vector2f location, double hight, double width): StaticObject(diamond,location, hight, width)
{
}
//-------------------------------------------------------
//����� �������� �� ����� �� ����
void Diamond::colide(Digger& digeer)
{
	if (digeer.getDiamondsLeft() != 0)
	{
		digeer.setDiamond(-1);//����� ������ ������ �� �����
		digeer.addScore(15);
		m_toEarse=true;
	}
}
//-------------------------------------------------------
//����� �������� �� ����� �� �����
void Diamond::colide(Monster& monster)
{
}
