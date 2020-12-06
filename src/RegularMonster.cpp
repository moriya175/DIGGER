#include "RegularMonster.h"
//-------------------------------------------------------
//בנאי של מפלצת רגילה
RegularMonster::RegularMonster(sf::Vector2f location, double hight, double width):Monster(location, hight, width)
{
}
//-------------------------------------------------------
//תזוזת מפלצת רגילה זזה בצורה רנדומלית
void RegularMonster::move(sf::Time deltaTime)
{
	srand(time(0));
	if (m_numOfstep == MAXSTEP)
	{	
		int direction = rand() % NUM_OF_DIRECTION;
		m_nextDirection = (Directions(direction));
		m_numOfstep = 0;
	}	
	Monster::move(deltaTime);
	moveSprite(deltaTime);
	m_numOfstep++;
}
//-------------------------------------------------------