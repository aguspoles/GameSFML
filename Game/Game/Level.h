#ifndef LEVEL_H
#define LEVEL_H
#include "Credits.h"
#include "MusicPlayer.h"
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
	MusicPlayer* _musicPlayer;

	const std::string TEXTURES_PATH = "../Game/Assets/Textures/";

public:
	Level();
	~Level();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();

	void CheckState();
};

#endif