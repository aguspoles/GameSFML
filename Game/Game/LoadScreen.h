#ifndef LOADSCREEN_H
#define LOADSCREEN_H
#include "Level.h"

class LoadScreen :
	public Game
{
private:
	bool _loaded;
	sf::Text _text;
	sf::Font _font;

	const std::string FONTS_PATH = "Assets/Fonts/";
public:
	LoadScreen();
	~LoadScreen();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();

	void LoadAssets();
};

#endif