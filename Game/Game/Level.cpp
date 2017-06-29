#include "Level.h"

#define CANT_ENEMIES 10

Level::Level()
{
	_backgroundTexture.loadFromFile(TEXTURES_PATH + "BG.png");
	_background.setTexture(_backgroundTexture);
	_background.setScale(0.4, 0.524);
	_musicPlayer = new MusicPlayer();
}


Level::~Level() 
{
	for each(Entity* entitie in _entities)
	{
		if (entitie)
			delete entitie;
	}
	_entities.clear();

	if (_musicPlayer) delete _musicPlayer;
}

void Level::Init()
{
	LoadAssets();

	srand(time(NULL));
	int posX;
	int posY;
	Player* _player = new Player();
	_entities.push_back(_player);
	Enemy* enemies[CANT_ENEMIES];
	PickUp* picks[CANT_ENEMIES];
	for (size_t i = 0; i < CANT_ENEMIES; i++)
	{
		enemies[i] = new PumpkinBoy();
		picks[i] = new PickUp();
		_entities.push_back(enemies[i]);
		_entities.push_back(picks[i]);
	}
	int randomX1 = (int)(enemies[0]->GetSprite()->getGlobalBounds().width);
	int randomX = _window->getSize().x - randomX1;
	int randomY1 = (int)(enemies[0]->GetSprite()->getGlobalBounds().height);
	int randomY = _window->getSize().y - randomY1;
	for (int i = 0; i < CANT_ENEMIES; i++)
	{
		posX = randomX1 + rand() % randomX;
		posY = randomX1 + rand() % randomY;
		enemies[i]->GetSprite()->setPosition(posX, posY);
		picks[i]->GetSprite()->setPosition(posX, posY);
		enemies[i] = NULL;//el borrado lo hago desde el destructor;
	}

	for each(Entity* entitie in _entities)
	{
		entitie->SetWindow(_window);
		entitie->Init();
	}
	_musicPlayer->Play(Music::LevelTheme);
}

void Level::Run()
{
	Init();
	while (_window->isOpen())
	{
		Game::ElapsedTime();

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

void Level::Update()
{
	CheckState();
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
			if (*it)
			{
				delete *it;
				*it = NULL;
			}
		}
	}
}

void Level::Draw()
{
	_window->draw(_background);
	for each(Entity* entitie in _entities)
	{
		if (entitie)
			entitie->Draw();
	}
	Score::ShowScore(_window);
}

void Level::Destroy()
{
	
}

void Level::LoadAssets()
{
	Player::TextureMap[PlayerTextures::IDLE] = sf::Texture();
	Player::TextureMap[PlayerTextures::IDLE].loadFromFile(Player::TEXTURES_PATH + "Idle.png");
	Player::TextureMap[PlayerTextures::RUN] = sf::Texture();
	Player::TextureMap[PlayerTextures::RUN].loadFromFile(Player::TEXTURES_PATH + "Run.png");
	Player::TextureMap[PlayerTextures::SHOOT] = sf::Texture();
	Player::TextureMap[PlayerTextures::SHOOT].loadFromFile(Player::TEXTURES_PATH + "Shoot.png");

	PumpkinBoy::TextureMap[PumpKinTextures::RUN] = sf::Texture();
	PumpkinBoy::TextureMap[PumpKinTextures::RUN].loadFromFile(PumpkinBoy::TEXTURES_PATH + "Run.png");

	PickUp::TextureMap[PickUpAssets::SKELETON] = sf::Texture();
	PickUp::TextureMap[PickUpAssets::SKELETON].loadFromFile(PickUp::TEXTURES_PATH + "Skeleton.png");

	PickUp::TextureMap[PickUpAssets::PICK] = sf::Texture();
	PickUp::TextureMap[PickUpAssets::PICK].loadFromFile(PickUp::TEXTURES_PATH + "PickSkeleton.png");
	PickUp::SoundMap[PickUpAssets::PICKSOUND] = SoundEffect();
	PickUp::SoundMap[PickUpAssets::PICKSOUND].LoadSound(PickUp::SOUND_PATH + "jump_05.wav");
}

void Level::CheckState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		Score::SaveHighScore();
		Score::SCORE = 0;
		_musicPlayer->Stop();
		SwitchState(new Credits());
	}
}


