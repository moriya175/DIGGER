#include "StaticObject.h"
//-------------------------------------------------------
//בנאי עבור האובייקטים הסטטיים מאתחל ספרייט
StaticObject::StaticObject(NamesOfPicture index, sf::Vector2f location, double hight, double width): m_toEarse(false),m_picture(updateSprite(Resources::getinstance().getTexture(index), location, hight, width))
{
}
//-------------------------------------------------------
//ציור ספרייט של אובייקט סטטי
void StaticObject::draw(sf::RenderWindow& window)
{
	window.draw(m_picture);
}
//-------------------------------------------------------
//בדיקה עם למחוק
bool StaticObject::checkEarse()
{
	return m_toEarse;
}
//-------------------------------------------------------		