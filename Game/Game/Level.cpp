#include "Level.h"

#define CANT_ENEMIES 10

Level::Level() 
{
}


Level::~Level() 
{
	for each(Entity* entitie in _entities)
	{
		if (entitie)
			delete entitie;
	}
	_entities.clear();
}

void Level::Init()
{
	srand(time(NULL));
	int posX;
	int posY;
	Player* _player = new Player();
	Enemy* enemies[CANT_ENEMIES];
	_entities.push_back(_player);
	/*for (int i = 0; i < CANT_ENEMIES; i++)
	{
		posX = 50 + rand() % (_window->getSize().x + 1 - 50);
		posY = 50 + rand() % (_window->getSize().y + 1 - 50);
		enemies[i] = new Enemy(sf::Vector2f(posX, posY), "idle.gif");
		_entities.push_back(enemies[i]);
	}*/

	for each(Entity* entitie in _entities)
	{
		entitie->SetWindow(_window);
	}
}

void Level::Run()
{
	Init();
	while (_window->isOpen())
	{
		Game::ElapsedTime();
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
			if (entitie)
				entitie->Draw();
		}

		_window->display(); 
	}
	Destroy();
}

void Level::Update()
{
	for(std::list<Entity*>::iterator it = _entities.begin(); it != _entities.end(); it++)
	{
		if (*it && (*it)->IsVisible())
		{
			(*it)->Update();
			if ((*it)->GetType() == "Player")
			{
				Player *p = (Player*)*it;
				p->PlayerCollision(_entities);
			}
		}
		else
		{
			delete *it;
			*it = NULL;
		}
	}
}

void Level::Destroy()
{
	
}

