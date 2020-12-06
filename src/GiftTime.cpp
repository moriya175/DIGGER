#include "GiftTime.h"
//-------------------------------------------------------
//בנאי של מתנת הוספת זמן משתמש בבנאי של מתנה
GiftTime::GiftTime(sf::Vector2f location, double hight, double width) : Gift(gifttime, location, hight, width)
{
}
//-------------------------------------------------------
//טיפול בהתנגשות של מתנת זמן עם שחקן
void GiftTime::colide(Digger& digger)
{
	digger.addTime(30);
	m_toEarse=true;
}
//-------------------------------------------------------
//טיפול בהתנגשות של מתנת זמן עם מפלצת
void GiftTime::colide(Monster& monster)
{
}