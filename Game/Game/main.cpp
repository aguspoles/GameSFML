#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vld.h>
#include "Level.h"
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameSFML");
	Game* g = new Menu(&window);
	g->Run();

	delete g;
	return 0;
} 