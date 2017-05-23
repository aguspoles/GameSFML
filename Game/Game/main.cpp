#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game* g = new Game();
	g->Run();
	return 0;
}