#include "..\include\Resources.h"
//-------------------------------------------------------
//הבנאי שאחראי לזימון טעינת התמונות וסוג הטקסטים
Resources::Resources()
{
	m_font.loadFromFile("C:/Windows/Fonts/Forte.ttf");
	insertPicture();
	m_tuneGame.openFromFile("tune.wav");
	m_won.openFromFile("won.wav");
	m_gameover.openFromFile("gameover.wav");	
}
//-------------------------------------------------------
//טעינת התמונות
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
//פונקציה המחזירה מצביע לטקסטורה
sf::Texture* Resources::getTexture(const int index)
{
	return &(m_picture[index]);
}
//-------------------------------------------------------
//פונקציה סטטית לצורך תבנית עיצוב של סינגלטון 
Resources& Resources::getinstance()
{
	static Resources m_instence;
	return m_instence;
}
//-------------------------------------------------------