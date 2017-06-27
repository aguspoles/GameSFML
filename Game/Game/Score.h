#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

static class Score
{
private:
	static sf::Text _text;
	static sf::Font _font;

	static const std::string FONTS_PATH;
public:
	Score();
	~Score();

	static int HighScore;
	static void ShowScore(sf::RenderWindow* window);
};

#endif