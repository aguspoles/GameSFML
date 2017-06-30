#include "Credits.h"


Credits::Credits()
{
	_musicPlayer = new MusicPlayer();
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
	_window->draw(_text1);
	_window->draw(_text2);
	_window->draw(_text3);
	_window->draw(_text4);
}

void Credits::Init()
{
	_musicPlayer->Play(Music::LevelTheme);
	if (!_font1.loadFromFile(FONTS_PATH + "iomanoid.ttf")
		|| !_font.loadFromFile(FONTS_PATH + "bboron.ttf"))
	{
#ifdef DEBUG
		std::cout << "no se cargo la fuente";
#endif
	}
	_text.setFont(_font1);
	_text.setString("Made by Agustin Pollsechi");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text.setOrigin(0, 0);
	_text.setPosition(100, _window->getSize().y / 2 - _text.getCharacterSize() - 100);

	_text4 = _text3 = _text2 = _text1 = _text;
	_text1.setString("Assets from:");
	_text1.setPosition(50, _window->getSize().y / 2 - _text.getCharacterSize() - 20);

	_text2.setCharacterSize(25);
	_text2.setFont(_font);
	_text2.setString("http://www.gameart2d.com/freebies.html");
	_text2.setPosition(90, _window->getSize().y / 2 - _text.getCharacterSize() + 35);

	_text3.setCharacterSize(25);
	_text3.setFont(_font);
	_text3.setString("https://opengameart.org/content/platformer-jumping-sounds");
	_text3.setPosition(90, _window->getSize().y / 2 - _text.getCharacterSize() + 55);

	_text4.setCharacterSize(40);
	_text4.setFont(_font1);
	_text4.setString("Escape to return to Menu");
	_text4.setPosition(90, _window->getSize().y - _text.getCharacterSize() - 35);
}

void Credits::Destroy()
{
}
