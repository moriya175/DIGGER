#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class ExitGame:public Button
{
public:
	ExitGame();
	~ExitGame();
	virtual void handleClick(bool& startGame);
protected:
};