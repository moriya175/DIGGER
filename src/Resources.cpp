#include "..\include\Resources.h"
//-------------------------------------------------------
//����� ������ ������ ����� ������� ���� �������
Resources::Resources()
{
	m_font.loadFromFile("C:/Windows/Fonts/Forte.ttf");
	insertPicture();
	m_tuneGame.openFromFile("tune.wav");
	m_won.openFromFile("won.wav");
	m_gameover.openFromFile("gameover.wav");	
}
//-------------------------------------------------------
//����� �������
void Resources::insertPicture()
{
	auto img = sf::Texture();
	img.loadFromFile("diamond.PNG");
	m_picture.push_back(img);
	img.loadFromFile("wall.GIF");
	m_picture.push_back(img);
	img.loadFromFile("stone.PNG");
	m_picture.push_back(img);
    img.loadFromFile("giftscore.png");
	m_picture.push_back(img);
	img.loadFromFile("clock.png");
	m_picture.push_back(img);
	img.loadFromFile("giftstone.png");
	m_picture.push_back(img);
	img.loadFromFile("menu.jpg");
	m_picture.push_back(img);
	img.loadFromFile("newgame.png");
	m_picture.push_back(img);
	img.loadFromFile("exit.png");
	m_picture.push_back(img);
	img.loadFromFile("digger1.png");
	m_picture.push_back(img);
	img.loadFromFile("digger2.png");
	m_picture.push_back(img);
	img.loadFromFile("digger3.png");
	m_picture.push_back(img);
	img.loadFromFile("monster1.png");
	m_picture.push_back(img);
	img.loadFromFile("monster2.png");
	m_picture.push_back(img);
	img.loadFromFile("monster3.png");
	m_picture.push_back(img);
	img.loadFromFile("monster4.png");
	m_picture.push_back(img);
	img.loadFromFile("background.jpg");
	m_picture.push_back(img);
	img.loadFromFile("gameover.jpg");
	m_picture.push_back(img);
	img.loadFromFile("won.png");
	m_picture.push_back(img);
}
//-------------------------------------------------------
//������� ������� ����� ��������
sf::Texture* Resources::getTexture(const int index)
{
	return &(m_picture[index]);
}
//-------------------------------------------------------
//������� ����� ����� ����� ����� �� �������� 
Resources& Resources::getinstance()
{
	static Resources m_instence;
	return m_instence;
}
//-------------------------------------------------------