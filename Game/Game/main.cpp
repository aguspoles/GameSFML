#ifdef DEBUG
#include <vld.h>
#endif // DEBUG

#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameSFML");
	Score* score = new Score();
	Game* g = new Menu(&window);
	g->Run();

	delete g;
	delete score;
	return 0;
} 