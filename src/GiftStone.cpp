#include "GiftStone.h"
//-------------------------------------------------------
//���� �� ���� ����� ����� ������ ����� ����� �� ����
GiftStone::GiftStone( sf::Vector2f location, double hight, double width) : Gift(giftstone, location, hight, width)
{
}
//-------------------------------------------------------
//����� �������� �� ���� ����� �� ����
void GiftStone::colide(Digger& digeer)
{
	digeer.addStones();
	m_toEarse = true;
}
//-------------------------------------------------------
//����� �������� �� ���� ����� �� �����
void GiftStone::colide(Monster& monster)
{
}
