#include "GiftStone.h"
//-------------------------------------------------------
//בנאי של מתנת הוספת אבנים לאכילה משתמש בבנאי של מתנה
GiftStone::GiftStone( sf::Vector2f location, double hight, double width) : Gift(giftstone, location, hight, width)
{
}
//-------------------------------------------------------
//טיפול בהתנגשות של מתנת אבנים עם שחקן
void GiftStone::colide(Digger& digeer)
{
	digeer.addStones();
	m_toEarse = true;
}
//-------------------------------------------------------
//טיפול בהתנגשות של מתנת אבנים עם מפלצת
void GiftStone::colide(Monster& monster)
{
}
