#include "PumpkinBoy.h"

std::map<PumpKinTextures::TextureID, sf::Texture> PumpkinBoy::_textureMap;
std::map<PumpKinTextures::TextureID, bool> PumpkinBoy::_texturesLoaded;
const float PumpkinBoy::Speed = 50;

PumpkinBoy::PumpkinBoy() : _directionFlag(true), _isLookingRight(true)
{
	_sprite.setOrigin(290, 381);
	_sprite.scale(0.1, 0.1);
	if (_texturesLoaded[PumpKinTextures::RUN] == false)//lo cargamos solo para el primer enemigo
	{
		_textureMap[PumpKinTextures::RUN] = sf::Texture();
		_textureMap[PumpKinTextures::RUN].loadFromFile(TEXTURES_PATH + "Run.png");
		_texturesLoaded[PumpKinTextures::RUN] = true;
	}
	_runAnimation = new Animation(&_sprite, sf::Vector2i(579, 763), 8, 0.5, true);
	_sprite.setTexture(_textureMap[PumpKinTextures::RUN]);
}

PumpkinBoy::PumpkinBoy(const sf::Vector2f & pos) : Enemy(pos)
{
	_sprite.setOrigin(290, 381);
	_sprite.scale(0.1, 0.1);
	if (_texturesLoaded[PumpKinTextures::RUN] == false)//lo cargamos solo para el primer enemigo
	{
		_textureMap[PumpKinTextures::RUN] = sf::Texture();
		_textureMap[PumpKinTextures::RUN].loadFromFile(TEXTURES_PATH + "Run.png");
		_texturesLoaded[PumpKinTextures::RUN] = true;
	}
	_runAnimation = new Animation(&_sprite, sf::Vector2i(579, 763), 8, 0.5, true);
	_sprite.setTexture(_textureMap[PumpKinTextures::RUN]);
}


PumpkinBoy::~PumpkinBoy()
{
	if (_runAnimation)
		delete _runAnimation;
}

void PumpkinBoy::Init()
{
}

void PumpkinBoy::Update()
{
	_elapsedSpeed = Game::Time() * Speed;
	Move();
	Animate();
}

void PumpkinBoy::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void PumpkinBoy::Move()
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

void PumpkinBoy::Animate()
{
	_runAnimation->Play(&_textureMap[PumpKinTextures::RUN]);
}

//std::string PumpkinBoy::GetType() const
//{
//	return "PumpKinBoy";
//}
