#include "Stone.h"
//-------------------------------------------------------
//���� �� ��� 
Stone::Stone(sf::Vector2f location, double hight, double width) : StaticObject(stone ,location, hight, width)
{
}
//-------------------------------------------------------
//����� �������� �� ���� �� ���
void Stone::colide(Digger& digeer)
{
	if (digeer.getStone()!=0)//�� �� ��� ����� �����
	{
		digeer.reduseStone();//����� �����
		 m_toEarse=true;
	}
}
//-------------------------------------------------------
//����� �������� �� ����� �� ���
void Stone::colide(Monster& monster)
{
	monster.updateToPrevPosition();
}
