#include "Wall.h"
//-------------------------------------------------------

//בנאי של קיר
Wall::Wall(sf::Vector2f location, double hight, double width) : StaticObject(wall, location, hight, width)
{}
//-------------------------------------------------------
//טיפול בהתנגשות של שחקן עם קיר
void Wall::colide(Digger& digeer)
{
	digeer.updateToPrevPosition();
	 m_toEarse=false;
}
//-------------------------------------------------------
//טיפול בהתנגשות של מפלצת עם קיר
void Wall::colide(Monster& monster)
{
	monster.updateToPrevPosition();
}

