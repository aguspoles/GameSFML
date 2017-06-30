#include "Menu.h"

Menu::Menu() : _clima("not available")
{
	_musicPlayer = new MusicPlayer();
}

Menu::Menu(sf::RenderWindow * window) : _clima("not available")
{
	_window = window;
	_musicPlayer = new MusicPlayer();
}


Menu::~Menu()
{
	if (_musicPlayer) delete _musicPlayer;
}

void Menu::Init()
{
	if (!_font.loadFromFile(FONTS_PATH + "iomanoid.ttf"))
	{
#ifdef DEBUG
		std::cerr << "no se cargo la fuente";
#endif
	}
	_text.setFont(_font);
	_text.setString("Press Space to begin");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text.setOrigin(0, 0);
	_text.setPosition(175, _window->getSize().y / 2 - _text.getCharacterSize());

	WebRequest();
	ShowWebReq();
	Score::LoadHighScore();
	_musicPlayer->Play(Music::MenuTheme);
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
		SwitchState(new LoadScreen());
	}
}

void Menu::Draw()
{
	_window->draw(_text);
	_window->draw(_text1);
	Score::ShowHighScore(_window);
}

void Menu::Destroy()
{

}

void Menu::WebRequest()
{
	LoadCityFromFile();

	sf::Http http;
	http.setHost("http://query.yahooapis.com/");
	sf::Http::Request request;
	sf::Http::Response response;

	try
	{
		request.setUri("/v1/public/yql?q=select%20item.condition.text%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22"
			+ _city + "%2C%20tx%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
		response = http.sendRequest(request);
		if (response.getStatus() == sf::Http::Response::Ok)
		{
			std::string s = response.getBody();
			auto j = json::parse(s.begin(), s.end());
			std::string clima = j["query"]["results"]["channel"]["item"]["condition"]["text"];
#ifdef DEBUG
			std::cout << "Clima:" << clima;
#endif
			_clima = clima;
		}
	}
	catch (std::exception)
	{
		std::cout << "Nombre incorrecto" << std::endl;
	}
}

void Menu::LoadCityFromFile()
{
	std::ifstream loadFile;
	loadFile.open("../Assets/web.txt");
	if (loadFile.fail())
	{
#ifdef DEBUG
		std::cerr << "Unable to open file" << std::endl;
#endif
	}
	else
	{
		loadFile >> _city;
		loadFile.close();
	}
}

void Menu::ShowWebReq()
{
	_text1.setFont(_font);
	_text1.setString("Weather in " + _city + " is " + _clima);
	_text1.setCharacterSize(25); // in pixels, not points!
	_text1.setFillColor(sf::Color::Red);
	_text1.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text1.setOrigin(0, 0);
	_text1.setPosition(15, 40);
}
