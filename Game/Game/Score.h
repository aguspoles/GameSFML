#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#if DEBUG
#include <iostream>
#endif

class Score
{
private:
	static sf::Text _text;
	static sf::Font _font;

	static const std::string FONTS_PATH;
	static int HighScore;
public:
	Score();
	~Score();

	static int SCORE;
	static void ShowScore(sf::RenderWindow* window);
	static void ShowHighScore(sf::RenderWindow* window);
	static void SaveHighScore();
	static void LoadHighScore();
};

#endif