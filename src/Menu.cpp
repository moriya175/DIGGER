#include "Menu.h"
//-------------------------------------------------------
//���� �� ����� ����� ������ �� �������
Menu::Menu():m_picture(*Resources::getinstance().getTexture(menu))
{
	m_button.push_back(new ExitGame());
	m_button.push_back(new NewGame());
}
//-------------------------------------------------------
//���� �� ������ ��������
Menu::~Menu()
{
	for (auto bptr : m_button)
		delete bptr;
}
//-------------------------------------------------------
//���� ���� ������ ������ ���� �������
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_picture);
	for (auto button : m_button)
		button->draw(window);
}
//-------------------------------------------------------
//����� ������ �� �����
void Menu::handleClick(const sf::Vector2f& location,bool &startgame, bool &buttonPressed)
{
	for (auto button : m_button)
		if (button->checkPosition(location, WIDTHBUTTON, HIGHTBUTTON))
		{
			buttonPressed = true;
			button->handleClick(startgame);
			return;
		}
}
//-------------------------------------------------------
//����� ������
void Menu::displaymenu(sf::RenderWindow& window, bool& startgame)
{
	bool  buttonPressed = false;
	sf::Event event;
	while (window.isOpen() && !buttonPressed)
	{
		window.clear();
	    draw(window);
		window.display();
		if (window.waitEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				handleClick(location, startgame, buttonPressed);
			}
		}
	}
	if (!startgame)
	{
		window.close();
		return;
	}
}
//-------------------------------------------------------