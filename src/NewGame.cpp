#include "NewGame.h"
//-------------------------------------------------------
//���� �� ����� ���� ���
NewGame::NewGame() :Button(Resources::getinstance().getTexture(newgame), HIGHTBUTTON, WIDTHBUTTON, { BUTTONLOCATION,BUTTONLOCATION })
{
}
//-------------------------------------------------------
//����� ������
void NewGame::handleClick(bool& startGame)
{
	startGame = true;
}
