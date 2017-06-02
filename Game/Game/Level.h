#pragma once
#include "Game.h"
#include "Menu.h"

class Level :
	public Game
{
private:
	std::list<Entity*> _entities;
public:
	Level();
	~Level();

	void Run();
	void Update();
	void Init();
	void Destroy();
};

