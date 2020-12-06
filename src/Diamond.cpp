#include "Diamond.h"
//-------------------------------------------------------
//הבנאי של יהלום
Diamond::Diamond(sf::Vector2f location, double hight, double width): StaticObject(diamond,location, hight, width)
{
}
//-------------------------------------------------------
//טיפול בהתנגשות של יהלום עם שחקן
void Diamond::colide(Digger& digeer)
{
	if (digeer.getDiamondsLeft() != 0)
	{
		digeer.setDiamond(-1);//נפחית מהכמות שנשארה לו לאכול
		digeer.addScore(15);
		m_toEarse=true;
	}
}
//-------------------------------------------------------
//טיפול בהתנגשות של יהלום עם מפלצת
void Diamond::colide(Monster& monster)
{
}
