#pragma once
#include "Game.h"
#include "MusicPlayer.h"

class Credits :
	public Game
{
private:
	sf::Text _text;
	sf::Font _font;
	MusicPlayer* _musicPlayer;

	const std::string FONTS_PATH = "../Game/Assets/Fonts/";

public:
	Credits();
	~Credits();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();
};

