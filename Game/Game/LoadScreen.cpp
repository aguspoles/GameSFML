#include "LoadScreen.h"



LoadScreen::LoadScreen() : _loaded(false)
{
}


LoadScreen::~LoadScreen()
{
}

void LoadScreen::Run()
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
	    LoadAssets();
	}
}

void LoadScreen::Update()
{
	if(_loaded)
		SwitchState(new Level());
}

void LoadScreen::Draw()
{
	_window->draw(_text);
}

void LoadScreen::Init()
{
	if (!_font.loadFromFile(FONTS_PATH + "iomanoid.ttf"))
	{
#ifdef DEBUG
		std::cerr << "no se cargo la fuente";
#endif
	}
	_text.setFont(_font);
	_text.setString("LOADING...");
	_text.setCharacterSize(50); // in pixels, not points!
	_text.setFillColor(sf::Color::Red);
	_text.setStyle(sf::Text::Bold | sf::Text::Italic);
	_text.setOrigin(0, 0);
	_text.setPosition(280, _window->getSize().y / 2 - _text.getCharacterSize());
}

void LoadScreen::Destroy()
{

}

void LoadScreen::LoadAssets()
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

	Zombie::TextureMap[ZombieTextures::RUN] = sf::Texture();
	Zombie::TextureMap[ZombieTextures::RUN].loadFromFile(Zombie::TEXTURES_PATH + "Run.png");

	_loaded = true;
}
