#ifndef MENU_H
#define MENU_H
#include "SFML\Network.hpp"
#include "LoadScreen.h"
#include "MusicPlayer.h"
#include "json.hpp"
using json = nlohmann::json;

class Menu :
	public Game
{
private:
	sf::Text _text, _text1;
	sf::Font _font;
	MusicPlayer* _musicPlayer;

	std::string _city;
	std::string _clima;
	
	const std::string FONTS_PATH = "Assets/Fonts/";

public:
	Menu();
	Menu(sf::RenderWindow* window);
	~Menu();

	void Run();
	void Update();
	void Draw();
	void Init();
	void Destroy();

	void WebRequest();
	void LoadCityFromFile();
	void ShowWebReq();
};

#endif