#include "GiftScore.h"
//-------------------------------------------------------
//���� �� ���� ����� ����� ���� ����� �� ����
GiftScore::GiftScore(sf::Vector2f location, double hight, double width) : Gift(giftscore, location, hight, width)
{
}
//-------------------------------------------------------
//����� �������� �� ���� �� ���� �����
void GiftScore::colide(Digger& digeer)
{
	digeer.addScore(10);
	m_toEarse=true;
}
//-------------------------------------------------------
//����� �������� �� ����� �� ���� �����
void GiftScore::colide(Monster& monster)
{
}