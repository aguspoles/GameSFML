#include "Score.h"

int Score::HighScore = 0;
sf::Text Score::_text;
sf::Font Score::_font;
const std::string Score::FONTS_PATH = "../Game/Assets/Fonts/";

Score::Score()
{
	if (!_font.loadFromFile(FONTS_PATH + "iomanoid.ttf"))
	{
		//std::cout << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Score " + std::to_string(HighScore));
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
	_text.setString("Score " + std::to_string(HighScore));
	window->draw(_text);
}
