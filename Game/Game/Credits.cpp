#include "Credits.h"
#include "Menu.h"


Credits::Credits()
{
	_musicPlayer = new MusicPlayer();
	_musicPlayer->Play(Music::LevelTheme);
}


Credits::~Credits()
{
	if (_musicPlayer) delete _musicPlayer;
}

void Credits::Run()
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

void Credits::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		_musicPlayer->Stop();
		SwitchState(new Menu());
	}
}


void Credits::Draw()
{
	_window->draw(_text);
}

void Credits::Init()
{
	if (!_font.loadFromFile(FONTS_PATH + "bboron.ttf"))
	{
		std::cout << "no se cargo la fuente";
	}
	_text.setFont(_font);
	_text.setString("Made by Agustin Pollsechi");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text.setOrigin(0, 0);
	_text.setPosition(175, _window->getSize().y / 2 - _text.getCharacterSize());
	//_text.setPosition(150, _window->getSize().y / 2 - _text.getCharacterSize() + 30);
	//_text.setString("Assets from:");
}

void Credits::Destroy()
{
}
