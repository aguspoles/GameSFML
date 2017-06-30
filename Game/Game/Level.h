#ifndef LEVEL_H
#define LEVEL_H
#include "Credits.h"
#include "MusicPlayer.h"
#include "PumpkinBoy.h"
#include "Player.h"
#include "PickUp.h"
#include "Zombie.h"

class Level :
	public Game
{
private:
	std::list<Entity*> _entities;
	sf::Sprite _background;
	sf::Texture _backgroundTexture;
	MusicPlayer* _musicPlayer;

	sf::Text _text;
	sf::Font _font;

	const std::string TEXTURES_PATH = "Assets/Textures/";
	const std::string FONTS_PATH = "Assets/Fonts/";

public:
	Level();
	~Level();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();

	void AddEntities();

	void CheckState();
};

#endif