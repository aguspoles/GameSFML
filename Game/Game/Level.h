#ifndef LEVEL_H
#define LEVEL_H
#include "Game.h"
#include "Menu.h"

class Level :
	public Game
{
private:
	//float _elapsed;
	std::list<Entity*> _entities;
public:
	Level();
	~Level();

	void Run();
	void Update();
	void Init();
	void Destroy();
};

#endif