#include "PickUp.h"

std::map<std::string, sf::Texture> PickUp::_textureMap;
std::map<std::string, bool> PickUp::_texturesLoaded;

PickUp::PickUp()
{
	_sprite.setOrigin(51, 25);
	_sprite.scale(0.5, 0.5);
	_sprite.setPosition(150, 50);
	if (_texturesLoaded["Skeleton"] == false)
	{
		_textureMap["Skeleton"] = sf::Texture();
		_textureMap["Skeleton"].loadFromFile("../Game/Textures/Skeleton.png");
		_texturesLoaded["Skeleton"] = true;
	}
	if (_texturesLoaded["Pick"] == false)
	{
		_textureMap["Pick"] = sf::Texture();
		_textureMap["Pick"].loadFromFile("../Game/Textures/PickSkeleton.png");
		_texturesLoaded["Pick"] = true;
	}
	_pickAnimation = new Animation(&_sprite, sf::Vector2i(128, 128), 4, 1, true);
	_sprite.setTexture(_textureMap["Skeleton"]);
}


PickUp::~PickUp()
{
	if (_pickAnimation)
		delete _pickAnimation;
}

void PickUp::Init()
{
}

void PickUp::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void PickUp::Update()
{
	_sprite.rotate(0.2);
}

void PickUp::Animate()
{
	_pickAnimation->Play(&_textureMap["Pick"]);
	_sprite.rotate(2);
}

std::string PickUp::GetType() const
{
	return "PickUp";
}

Animation PickUp::GetPickAnimation() const
{
	return *_pickAnimation;
}
