#include "Game.h"



Game::Game()
{
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "GameSFML");
}


Game::~Game()
{
	delete _window;
}

void Game::Init()
{
	srand(time(NULL));
	int posX;
	int posY;
	Player* _player = new Player();
	Enemy* enemies[CANT_ENEMIES];
	for (int i = 0; i < CANT_ENEMIES; i++)
	{
		posX = 50 + rand() % (_window->getSize().x + 1 - 50);
		posY = 50 + rand() % (_window->getSize().y + 1 - 50);
		enemies[i] = new Enemy(sf::Vector2f(posX, posY), "idle.gif");
	    _entities.push_back(enemies[i]);
	}
	_entities.push_back(_player);

	for each(Entity* entitie in _entities)
	{
		entitie->SetWindow(_window);
	}
}

void Game::Run()
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

		for each(Entity* entitie in _entities)
		{
			entitie->Draw();
		}

		_window->display();
	}
	Destroy();
}

void Game::Update()
{
	for each(Entity* entitie in _entities)
	{
		if (entitie->IsVisible())
		{
			entitie->Update();
			if (entitie->GetType() == "Player")
			{
				Player *p = (Player*)entitie;
				p->PlayerCollision(_entities);
			}
		}
		else
		{
			delete entitie;
			_entities.remove(entitie);
		}
	}
	
}

void Game::Destroy()
{
	for each(Entity* entitie in _entities)
	{
		if(entitie)
		  delete entitie;
	}
	_entities.clear();
}
