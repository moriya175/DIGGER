#pragma once
#include "Gift.h"
#include "Digger.h"
class GiftScore :public Gift
{
public:
	GiftScore(sf::Vector2f location, double hight, double width);
	~GiftScore() = default;
	virtual void colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:
};