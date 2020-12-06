#include "Stone.h"
//-------------------------------------------------------
//בנאי של אבן 
Stone::Stone(sf::Vector2f location, double hight, double width) : StaticObject(stone ,location, hight, width)
{
}
//-------------------------------------------------------
//טיפול בהתנגשות של שחקן עם אבן
void Stone::colide(Digger& digeer)
{
	if (digeer.getStone()!=0)//אם יש עוד אבנים לאכול
	{
		digeer.reduseStone();//נוריד אבנים
		 m_toEarse=true;
	}
}
//-------------------------------------------------------
//טיפול בהתנגשות של מפלצת עם אבן
void Stone::colide(Monster& monster)
{
	monster.updateToPrevPosition();
}
