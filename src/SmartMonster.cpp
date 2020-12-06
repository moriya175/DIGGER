#include "SmartMonster.h"
#include "Board.h"
//-------------------------------------------------------
//בנאי של מפלצת חכמה שמבל דיגר לצורך המיקום
SmartMonster::SmartMonster(sf::Vector2f location, double hight, double width,Digger& digger, Board& board):m_digger(digger),Monster(location, hight, width),m_board(board)
{}
//-------------------------------------------------------
//תזוזת המפלצות החכמות
void SmartMonster::move(sf::Time deltaTime)
{
	float DistanseFromPlayer, minDistanseFromPlayer= WINDOWSIDE* WINDOWSIDE;
	sf::Vector2f possibleDestigntion, direct,minDestination;
	for (int direction = 0; direction < NUMOFDIRECTION; direction++)
	{
		direct = calculateDirection(Directions(direction));
		possibleDestigntion = (((direct*SPEED) * (deltaTime.asSeconds())) + m_pictures[0].getPosition());
		DistanseFromPlayer = distanseFromPlayer(possibleDestigntion);
		if (DistanseFromPlayer < minDistanseFromPlayer)
		{
			m_nextDirection = getDirection(direct);
			minDistanseFromPlayer = DistanseFromPlayer;
			minDestination = possibleDestigntion;
		}
	}
	if (m_board.isStone(minDestination) || m_board.isWall(minDestination))
	{
		srand(time(0));
		m_nextDirection = Directions(rand() % NUMOFDIRECTION);
	}
	Monster::move(deltaTime);
	moveSprite(deltaTime);
}
//-------------------------------------------------------
//חישוב מרחק ע"פ מנהטן בין מפלצת לשחקן
float SmartMonster::distanseFromPlayer(sf::Vector2f possibleDestigntion)
{
	return (std::abs(possibleDestigntion.x - (m_digger.getPosition()).x) + std::abs(possibleDestigntion.y - (m_digger.getPosition()).y));
}
//-------------------------------------------------------