#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	_musicPlayer = new MusicPlayer();
	_musicPlayer->Play(Music::MenuTheme);
}

Menu::Menu(sf::RenderWindow * window) : Game()
{
	_window = window;
	
	_musicPlayer = new MusicPlayer();
	_musicPlayer->Play(Music::MenuTheme);
}


Menu::~Menu()
{
	if (_musicPlayer) delete _musicPlayer;
}

void Menu::Init()
{
	if (!_font.loadFromFile(FONTS_PATH + "iomanoid.ttf"))
	{
		std::cout << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Press Space to begin");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic | sf::Text::Underlined);
	_text.setOrigin(0, 0);
	_text.setPosition(175, _window->getSize().y / 2 - _text.getCharacterSize());
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
			if (event.type == sf::Event::Resized)
				_window->setSize(_window->getSize());
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
	    _musicPlayer->Stop();
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
