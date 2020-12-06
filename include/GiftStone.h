#pragma once
#include "Gift.h"
#include "Digger.h"
class GiftStone :public Gift
{
public:
	GiftStone(sf::Vector2f location, double hight, double width);
	~GiftStone() = default;
	virtual void colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:
};