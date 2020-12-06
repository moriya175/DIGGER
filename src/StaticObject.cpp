#include "StaticObject.h"
//-------------------------------------------------------
//���� ���� ���������� ������� ����� ������
StaticObject::StaticObject(NamesOfPicture index, sf::Vector2f location, double hight, double width): m_toEarse(false),m_picture(updateSprite(Resources::getinstance().getTexture(index), location, hight, width))
{
}
//-------------------------------------------------------
//���� ������ �� ������� ����
void StaticObject::draw(sf::RenderWindow& window)
{
	window.draw(m_picture);
}
//-------------------------------------------------------
//����� �� �����
bool StaticObject::checkEarse()
{
	return m_toEarse;
}
//-------------------------------------------------------		