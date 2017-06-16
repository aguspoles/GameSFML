#include "Menu.h"
#include <iostream>

Menu::Menu() 
{
	if (!_font.loadFromFile("../Game/Assets/Fonts/iomanoid.ttf"))
	{
		std::cout << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Hello world");
	_text.setCharacterSize(24); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic | sf::Text::Underlined);
}

Menu::Menu(sf::RenderWindow * window) : Game()
{
	_window = window;
	if (!_font.loadFromFile("../Game/Assets/Fonts/iomanoid.ttf"))
	{
		std::cout << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Press Space to begin");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic | sf::Text::Underlined);
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

		_window->clear(sf::Color::Black);

		Draw();

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

void Menu::Draw()
{
	_window->draw(_text);
}

void Menu::Destroy()
{

}
