#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "Level.h"
#include "MusicPlayer.h"

class Menu :
	public Game
{
private:
	sf::Text _text;
	sf::Font _font;
	MusicPlayer* _musicPlayer;

public:
	Menu();
	Menu(sf::RenderWindow* window);
	~Menu();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();
};

#endif