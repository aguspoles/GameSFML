#include "Score.h"

int Score::SCORE = 0;
int Score::HighScore = 0;
sf::Text Score::_text;
sf::Font Score::_font;
const std::string Score::FONTS_PATH = "../Game/Assets/Fonts/";

Score::Score()
{
	if (!_font.loadFromFile(FONTS_PATH + "iomanoid.ttf"))
	{
		std::cerr << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Score " + std::to_string(SCORE));
	_text.setCharacterSize(25); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text.setOrigin(0, 0);
	_text.setPosition(15, 15);
}


Score::~Score()
{
}

void Score::ShowScore(sf::RenderWindow* window)
{
	_text.setString("Score " + std::to_string(SCORE));
	window->draw(_text);
}

void Score::ShowHighScore(sf::RenderWindow * window)
{
	_text.setString("HighScore  " + std::to_string(HighScore));
	window->draw(_text);
}

void Score::SaveHighScore()
{
	if (SCORE > HighScore)
	{
		std::ofstream saveFile;
		saveFile.open("../save.txt");
		if (saveFile.fail())
			std::cerr << "Unable to open file" << std::endl;
		else
		{
			saveFile << HighScore;
			saveFile.close();
		}
	}
}

void Score::LoadHighScore()
{
	std::ifstream loadFile;
	loadFile.open("../save.txt");
	if (loadFile.fail())
		std::cerr << "Unable to open file" << std::endl;
	else
	{
		loadFile >> HighScore;
		loadFile.close();
	}
}
