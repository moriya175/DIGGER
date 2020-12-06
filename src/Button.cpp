#include "Button.h"
//-------------------------------------------------------
//���� ���� �����
Button::Button(sf::Texture* picture, double hight, double width, sf::Vector2f location): m_sprite(insertexture(picture, hight, width, location))
{
}
//-------------------------------------------------------
//������ ����� ������
void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//-------------------------------------------------------
//����� �� ������ ����� ������
bool Button::checkPosition(const sf::Vector2f& location, const float width, const float height) const//����� ��� ������ ������� ���� �� ������ ������
{
	auto rect = sf::RectangleShape({ width, height });
	rect.setPosition(m_sprite.getPosition());
	return(rect.getGlobalBounds().contains(location));
}
//-------------------------------------------------------
//���� �����
sf::Sprite& Button::insertexture(sf::Texture* picture, double hight, double width,sf::Vector2f location)
{
	auto sprite = sf::Sprite(*picture);
	sprite.setPosition(location);
	auto texSize = picture->getSize();
	auto newTexSize = sf::Vector2u(width, hight);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	sprite.scale(scaleX, scaleY);
	return sprite;
}
//-------------------------------------------------------