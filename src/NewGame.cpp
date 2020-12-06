#include "NewGame.h"
//-------------------------------------------------------
//בנאי של כפתור משחק חדש
NewGame::NewGame() :Button(Resources::getinstance().getTexture(newgame), HIGHTBUTTON, WIDTHBUTTON, { BUTTONLOCATION,BUTTONLOCATION })
{
}
//-------------------------------------------------------
//טיפול בלחיצה
void NewGame::handleClick(bool& startGame)
{
	startGame = true;
}
