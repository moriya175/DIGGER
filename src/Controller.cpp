#include "..\include\Controller.h"
//-------------------------------------------------------
//הבנאי של קונטרולר
Controller::Controller() :m_window(sf::VideoMode(WINDOWSIDE, WINDOWSIDE), "diggerGame"), m_menu()
{
}
//-------------------------------------------------------
//פנקציה שמנהל את ריצת התוכנית 
void Controller::run()
{
	srand(time(0));
	bool startgame = false;
	m_menu.displaymenu(m_window,startgame);
			while (startgame)
			{
				Game game;
				game.startGame(m_window);
				m_menu.displaymenu(m_window,startgame);
			}
}