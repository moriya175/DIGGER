#include "ExitGame.h"
//-------------------------------------------------------
//בנאי של כפתור יציאה משתמש בבנאי של כפתור
ExitGame::ExitGame() :Button(Resources::getinstance().getTexture(exitgame), HIGHTBUTTON, WIDTHBUTTON, { BUTTONLOCATION,BUTTONLOCATION + HIGHTBUTTON + 10 })
{
}
//-------------------------------------------------------
//טיפול בלחיצה על כפתור יציאה
void ExitGame::handleClick(bool& startGame)
{
	startGame = false;
	exit(0);
}
