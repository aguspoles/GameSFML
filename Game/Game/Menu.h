#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "Level.h"

class Menu :
	public Game
{
public:
	Menu();
	Menu(sf::RenderWindow* window);
	~Menu();

	void Run();
	void Update();
	void Init();
	void Destroy();
};

#endif