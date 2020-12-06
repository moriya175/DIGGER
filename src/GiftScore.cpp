#include "GiftScore.h"
//-------------------------------------------------------
//בנאי של מתנת הוספת ניקוד קורה לבנאי של מתנה
GiftScore::GiftScore(sf::Vector2f location, double hight, double width) : Gift(giftscore, location, hight, width)
{
}
//-------------------------------------------------------
//טיפןל בהתנגשות של שחקן עם מתנת ניקוד
void GiftScore::colide(Digger& digeer)
{
	digeer.addScore(10);
	m_toEarse=true;
}
//-------------------------------------------------------
//טיפןל בהתנגשות של מפלצת עם מתנת ניקוד
void GiftScore::colide(Monster& monster)
{
}