#include "GiftTime.h"
//-------------------------------------------------------
//���� �� ���� ����� ��� ����� ����� �� ����
GiftTime::GiftTime(sf::Vector2f location, double hight, double width) : Gift(gifttime, location, hight, width)
{
}
//-------------------------------------------------------
//����� �������� �� ���� ��� �� ����
void GiftTime::colide(Digger& digger)
{
	digger.addTime(30);
	m_toEarse=true;
}
//-------------------------------------------------------
//����� �������� �� ���� ��� �� �����
void GiftTime::colide(Monster& monster)
{
}