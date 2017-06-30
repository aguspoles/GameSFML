#ifndef CREDITS_H
#define CREDITS_H
#include "Game.h"
#include "Menu.h"
#include "MusicPlayer.h"

class Credits :
	public Game
{
private:
	sf::Text _text;
	sf::Text _text1;
	sf::Text _text2;
	sf::Text _text3;
	sf::Text _text4;
	sf::Font _font;
	sf::Font _font1;
	MusicPlayer* _musicPlayer;

	const std::string FONTS_PATH = "../Assets/Fonts/";

public:
	Credits();
	~Credits();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();
};

#endif