#pragma once
#include "Gift.h"
#include "Digger.h"
class GiftTime :public Gift
{
public:
	GiftTime(sf::Vector2f location, double hight, double width);
	~GiftTime() = default;
	virtual void colide(Digger& digger) override;
	virtual void colide(Monster& monster) override;
protected:
};