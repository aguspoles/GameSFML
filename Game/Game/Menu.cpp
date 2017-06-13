#include "Menu.h"

Menu::Menu() 
{

}

Menu::Menu(sf::RenderWindow * window) : Game()
{
	_window = window;
}


Menu::~Menu()
{
}

void Menu::Init()
{

}

void Menu::Run()
{
	Init();
	while (_window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				_window->close();
		}

		Update();

		_window->clear(sf::Color::White);
		_window->display();
	}
	Destroy();
}

void Menu::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		SwitchState(new Level());
	}
}

void Menu::Destroy()
{

}
