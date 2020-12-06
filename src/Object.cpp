#include "..\include\Object.h"
//-------------------------------------------------------
//יצירת ספריט ועדכון כל הפרטים
sf::Sprite Object::updateSprite(sf::Texture* picture, sf::Vector2f location, double hight, double width)
{
    auto sprite = sf::Sprite(*picture);
    sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize()/2u));
    sprite.setPosition(location);
    auto texSize = picture->getSize();
    auto newTexSize = sf::Vector2u(width, hight);
    auto scaleX = newTexSize.x * 1.00f / texSize.x;
    auto scaleY = newTexSize.y * 1.00f / texSize.y;
    sprite.scale(scaleX, scaleY);
    return sprite;
}
//-------------------------------------------------------