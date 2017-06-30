#include "Zombie.h"

std::map<ZombieTextures::TextureID, sf::Texture> Zombie::TextureMap;
const std::string Zombie::TEXTURES_PATH = "../Assets/Textures/Enemy/Zombie/";
const float Zombie::Speed = 15;

Zombie::Zombie() : _directionFlag(true), _isLookingRight(true)
{
	_sprite.setOrigin(215, 259.5);
	_sprite.scale(0.15, 0.15);

	_runAnimation = new Animation(&_sprite, sf::Vector2i(430, 519), 10, 0.8, true);
	_sprite.setTexture(TextureMap[ZombieTextures::RUN]);
}

Zombie::Zombie(const sf::Vector2f & pos)
{
	_sprite.setOrigin(215, 259.5);
	_sprite.scale(0.2, 0.1);

	_runAnimation = new Animation(&_sprite, sf::Vector2i(430, 519), 10, 0.5, true);
	_sprite.setTexture(TextureMap[ZombieTextures::RUN]);
}


Zombie::~Zombie()
{
	if (_runAnimation)
		delete _runAnimation;
}

void Zombie::Init()
{
}

void Zombie::Update()
{
	_elapsedSpeed = Game::Time() * Speed;
	Move();
	Animate();
}

void Zombie::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void Zombie::Move()
{
	if ((_sprite.getPosition().x < (_window->getSize().x - _sprite.getGlobalBounds().width / 2))
		&& _directionFlag)
	{
		if (!_isLookingRight)
		{
			_sprite.scale(-1, 1);
			_isLookingRight = true;
		}
		_sprite.move(_elapsedSpeed, 0);
	}
	else _directionFlag = false;
	if (_sprite.getPosition().x > _sprite.getGlobalBounds().width / 2 && !_directionFlag)
	{
		if (_isLookingRight)
		{
			_sprite.scale(-1, 1);
			_isLookingRight = false;
		}
		_sprite.move(-_elapsedSpeed, 0);
	}
	else _directionFlag = true;
}

void Zombie::Animate()
{
	_runAnimation->Play(&TextureMap[ZombieTextures::RUN]);
}

