#include "InformationDisplay.h"
//-------------------------------------------------------
//אתחול של הטקסטים הקבועים
InformationDisplay::InformationDisplay():m_flickerTime(true)
{
	m_printLives = sf::Text("Live:", Resources::getinstance().m_font);
	setText(m_printLives, sf::Vector2f(0 * WIDTHITEMINFO, HIGHTITEMINFO), LETERSIZE);
	m_printLevel = sf::Text("Level:", Resources::getinstance().m_font);
	setText(m_printLevel, sf::Vector2f(WIDTHITEMINFO, HIGHTITEMINFO), LETERSIZE);
	m_printScore = sf::Text("Score:", Resources::getinstance().m_font);
	setText(m_printScore, sf::Vector2f(2*WIDTHITEMINFO, HIGHTITEMINFO), LETERSIZE);
	m_printStone = sf::Text("Stone:", Resources::getinstance().m_font);
	setText(m_printStone, sf::Vector2f(3 * WIDTHITEMINFO, HIGHTITEMINFO), LETERSIZE);
}
//-------------------------------------------------------
//פונקציה להצגת מידע
void InformationDisplay::informationDisplay(sf::RenderWindow& window, const int stone, const int score, const int live, const int level, const int time)
{
	window.draw(m_printLives);
	auto text = sf::Text(std::to_string(live), Resources::getinstance().m_font);
	setText(text, sf::Vector2f(m_printLives.getGlobalBounds().width / 2 + m_printLives.getPosition().x, HIGHTITEMINFO + 30),LETERSIZE);
	window.draw(text);
	window.draw(m_printLevel);
    text = sf::Text(std::to_string(level), Resources::getinstance().m_font);
	setText(text, sf::Vector2f(m_printLevel.getGlobalBounds().width / 2 + m_printLevel.getPosition().x, HIGHTITEMINFO + 30), LETERSIZE);
	window.draw(text);
	window.draw(m_printScore);
	text = sf::Text(std::to_string(score), Resources::getinstance().m_font);
	setText(text, sf::Vector2f(m_printScore.getGlobalBounds().width / 2 + m_printScore.getPosition().x, HIGHTITEMINFO + 30), LETERSIZE);
	window.draw(text);
	window.draw(m_printStone);
	text = sf::Text(std::to_string(stone), Resources::getinstance().m_font);
	setText(text, sf::Vector2f(m_printStone.getGlobalBounds().width / 2 + m_printStone.getPosition().x, HIGHTITEMINFO + 30), LETERSIZE);
	window.draw(text);
	clockDisplay(window,time,text);
}
//-------------------------------------------------------
//פונקציה להצגת שעון דיגיטלי
void InformationDisplay::clockDisplay(sf::RenderWindow& window, const int time, sf::Text text)
{
	if ((time - (time % 60)) / 60 >= 10 && time % 60 >= 10)
		text = sf::Text(std::to_string((time - (time % 60)) / 60) + ":" + std::to_string(time % 60), Resources::getinstance().m_font);
	else if ((time - (time % 60)) / 60 < 10 && time % 60 >= 10)
		text = sf::Text(std::to_string(0) + std::to_string((time - (time % 60)) / 60) + ":" + std::to_string(time % 60), Resources::getinstance().m_font);
	else if ((time - (time % 60)) / 60 < 10 && time % 60 < 10)
		text = sf::Text(std::to_string(0) + std::to_string((time - (time % 60)) / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getinstance().m_font);
	else if ((time - (time % 60)) / 60 >= 10 && time % 60 < 10)
		text = sf::Text(std::to_string((time - (time % 60)) / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getinstance().m_font);
	text.setPosition(4 * WIDTHITEMINFO, HIGHTITEMINFO + 20);
	if ((time - (time % 60)) / 60 < 1&& (time % 60)<=30)
	{
		if (m_flickerTime)
		{
			text.setFillColor(sf::Color::Red);
			m_flickerTime = false;
		}
		else {
			text.setFillColor(sf::Color::Black);
			m_flickerTime = true;
		}
	}
	else text.setFillColor(sf::Color::Black);
	text.setCharacterSize(50);
	window.draw(text);
}
//-------------------------------------------------------
//פונקציה שעורכת טקסט
void InformationDisplay::setText(sf::Text& text, const sf::Vector2f& location, const int& size)
{
	text.setPosition(location);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(size);
}
//-------------------------------------------------------