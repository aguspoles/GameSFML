#ifndef LEVEL_H
#define LEVEL_H
#include "Game.h"
#include "Menu.h"
#include "PumpkinBoy.h"
#include "Player.h"
#include "PickUp.h"

class Level :
	public Game
{
private:
	std::list<Entity*> _entities;
	sf::Sprite _background;
	sf::Texture _backgroundTexture;
public:
	Level();
	~Level();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();
};

#endif