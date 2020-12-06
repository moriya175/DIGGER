#include "DinamikObject.h"

//-------------------------------------------------------
//פונקצית הכנסה לווקטור
void DinamikObject::insertToVector(std::vector<sf::Texture*> texture, sf::Vector2f location, double hight, double width)
{
	m_index = 0;
	for (auto text : texture)
		m_pictures.push_back(updateSprite(text, location, hight, width));
}
//-------------------------------------------------------
//ציור עבור אובייקטים דינמיים
void DinamikObject::draw(sf::RenderWindow& window)
{
	window.draw(m_pictures[m_index]);
	m_index++;
	if (m_index == m_pictures.size() )
		m_index = 0;
}
//-------------------------------------------------------
//בדיקה על גבולות הלוח
void DinamikObject::limitBoard()
{
	if (!(topLeft().x >= 0 && topLeft().y >= INFOHIGHT&& topLeft().y+ m_pictures[0].getGlobalBounds().height< WINDOWSIDE&& topLeft().x/*+ m_pictures[0].getGlobalBounds().width*/ <= WINDOWSIDE))
		updateToPrevPosition();
}
//-------------------------------------------------------
//החזרה למיקום קודם
void DinamikObject::updateToPrevPosition()
{
	for (auto& sprite : m_pictures)
		sprite.setPosition(m_prevPosition);
}
//-------------------------------------------------------
//פונקצית הוזזה לספרייטים
void DinamikObject::moveSprite(sf::Time deltaTime)
{
	if (checkNotOnExis())
	{
		if (checkDirection())
			m_direction = calculateDirection(m_nextDirection);
	}
	else 
	m_direction = calculateDirection(m_nextDirection);
	for(auto &sprite:m_pictures)
		sprite.move((SPEED*m_direction) * deltaTime.asSeconds());
	limitBoard();
}
//-------------------------------------------------------
//מחזירה כיוון ע"פ האינם שהתקבל
sf::Vector2f DinamikObject::calculateDirection(Directions direction)
{
	switch (direction)
	{
	case(Up):return { 0,-1 };break;
	case(Down):return  { 0,1 };break;
	case(Left):return { -1,0 };break;
	case(Right):return  { 1,0 };break;
	default:return { 0,0 };break;
	}
}
//-------------------------------------------------------
//בודקת אם יש שינוי בכיוון של 90 מעלות
bool DinamikObject::checkNotOnExis()
{
	if (((m_nextDirection == Right || m_nextDirection == Left) && (m_direction == calculateDirection(Up) || m_direction == calculateDirection(Down)))
		|| (((m_nextDirection == Up || m_nextDirection == Down) && (m_direction == calculateDirection(Right) || m_direction == calculateDirection(Left)))))
	return true;
	return false;
}
//-------------------------------------------------------
//מחזירה נקודה שמאלית עליונה
sf::Vector2f DinamikObject::topLeft()
{
	return (sf::Vector2f (m_pictures[0].getPosition().x - (0.5 * m_pictures[0].getGlobalBounds().width),
		m_pictures[0].getPosition().y - (0.5 * m_pictures[0].getGlobalBounds().height)));
}
//-------------------------------------------------------
//בדיקה אם מרחק האובייקט מהציר קטן מאפסילון מסוים את מקרבים אותו לציר
bool DinamikObject::checkDirection()
{
	auto width = m_pictures[0].getGlobalBounds().width;
	auto height = m_pictures[0].getGlobalBounds().height;
	auto x = topLeft().x;
	auto y = topLeft().y;
	auto newLocation = sf::Vector2f(-1, -1);
	switch (getDirection(m_direction))
	{
	case Right:if (std::abs(ceil((x + width) / width) * width - x - width) < EPSILON)
			newLocation = sf::Vector2f(std::ceil(((x + width) / width) * width) - width, y);break;
	case Left:if (std::abs(floor(x / width) * width - x) < EPSILON)
			newLocation = sf::Vector2f(std::floor(x / width) * width, y);break;
	case Up:if (std::abs((std::floor((y - INFOHIGHT) / height) * height) + INFOHIGHT- y) < EPSILON)
			newLocation = sf::Vector2f(x, (std::floor((y - INFOHIGHT) / height) * height) + INFOHIGHT);break;
	case Down:if (std::abs((std::ceil((y + height - INFOHIGHT) / height) * height) + INFOHIGHT- (y + height)) < EPSILON)
			newLocation = sf::Vector2f(x, std::abs((std::ceil((y + height - INFOHIGHT) / height) * height) + INFOHIGHT-(height)));break;
	}
	if (newLocation != sf::Vector2f(-1, -1))
	{
		sf::Vector2f centerlocation = {float( newLocation.x + (0.5 * width)),float(newLocation.y + (0.5 * height)) };
		for (int i = 0; i < m_pictures.size(); i++)
			m_pictures[i].setPosition(centerlocation);
		return true;
	}
	return false;
}
//-------------------------------------------------------
//מחזירה את הכיון
Directions DinamikObject::getDirection(sf::Vector2f direction) const
{
	 if (direction.x < 0)
		return Left;
	else if (direction.x > 0)
		return Right;
	else if (direction.y < 0)
		return Up;
	else if (direction.y > 0)
		return Down;
}
//-------------------------------------------------------
//מחזיה למיקום ההתחלתי
void DinamikObject::resetPosition()
{
	for (auto& sprite : m_pictures)
		sprite.setPosition(m_statlocation);
}
sf::FloatRect DinamikObject::getRectangle()
{
	return m_pictures[0].getGlobalBounds();
}
//----------------------------------------------------------
//מחזירה את התא המתנגש
sf::Vector2f DinamikObject::getCell() const
{
	auto cell = sf::Vector2f(-1, -1);
	int width = m_pictures[0].getGlobalBounds().width;
	int height = m_pictures[0].getGlobalBounds().height;
	auto x = m_pictures[0].getPosition().x - (0.5 * m_pictures[0].getGlobalBounds().width);
	auto y = m_pictures[0].getPosition().y - (0.5 * m_pictures[0].getGlobalBounds().height);
	switch (getDirection(m_direction))
	{
	case Up:
		cell = sf::Vector2f(floor((x + 2) / width), floor((y - INFOHIGHT + 2) / height));break;
	case Down:
		cell = sf::Vector2f(floor((x + 2) / width), (floor((y + height - INFOHIGHT - 2) / height)));break;
	case Right:
		cell = sf::Vector2f(floor(((x + width - 2) / width)), floor((y - INFOHIGHT + 2) / height));break;
	case Left:
		cell = sf::Vector2f(floor((x + 2) / width), floor((y - INFOHIGHT + 2) / height));break;
	default:
		break;
	}
	return cell;
}