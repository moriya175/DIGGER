#include "ExitGame.h"
//-------------------------------------------------------
//���� �� ����� ����� ����� ����� �� �����
ExitGame::ExitGame() :Button(Resources::getinstance().getTexture(exitgame), HIGHTBUTTON, WIDTHBUTTON, { BUTTONLOCATION,BUTTONLOCATION + HIGHTBUTTON + 10 })
{
}
//-------------------------------------------------------
//����� ������ �� ����� �����
void ExitGame::handleClick(bool& startGame)
{
	startGame = false;
	exit(0);
}
