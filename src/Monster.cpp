#include "Monster.h"
//-------------------------------------------------------
//אתחול ווקטור של תמונות עבור המפלצת
Monster::Monster(sf::Vector2f location, double hight, double width)
{
	insertToVector({Resources::getinstance().getTexture(monster1),Resources::getinstance().getTexture(monster2), Resources::getinstance().getTexture(monster3), Resources::getinstance().getTexture(monster4)}, location, hight, width);
	m_statlocation = location;
}
//-------------------------------------------------------
//עדכון של המיקום הקודם לפני התזוזה במידה ויש התנגשות
void Monster::move(sf::Time deltaTime)
{
	m_prevPosition = m_pictures[0].getPosition();
}
//-------------------------------------------------------


