#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Enemy.h"
#include <list>
#include <time.h>

#define CANT_ENEMIES 10

class Game
{
private:
	std::list<Entity*> _entities;
	sf::RenderWindow* _window;
public:
	Game();
	virtual ~Game();

	void Run();
	void Update();
	void Init();
	void Destroy();
};

