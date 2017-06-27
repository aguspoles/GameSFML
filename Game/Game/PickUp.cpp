#include "PickUp.h"

std::map<PickUpTextures::TextureID, sf::Texture> PickUp::_textureMap;
std::map<PickUpTextures::TextureID, bool> PickUp::_texturesLoaded;

PickUp::PickUp()
{
	_sprite.setOrigin(51, 25);
	_sprite.scale(0.5, 0.5);
	_sprite.setPosition(150, 50);
	if (_texturesLoaded[PickUpTextures::SKELETON] == false)
	{
		_textureMap[PickUpTextures::SKELETON] = sf::Texture();
		_textureMap[PickUpTextures::SKELETON].loadFromFile(TEXTURES_PATH + "Skeleton.png");
		_texturesLoaded[PickUpTextures::SKELETON] = true;
	}
	if (_texturesLoaded[PickUpTextures::PICK] == false)
	{
		_textureMap[PickUpTextures::PICK] = sf::Texture();
		_textureMap[PickUpTextures::PICK].loadFromFile(TEXTURES_PATH + "PickSkeleton.png");
		_texturesLoaded[PickUpTextures::PICK] = true;
	}
	_pickAnimation = new Animation(&_sprite, sf::Vector2i(128, 128), 4, 1, true);
	_sprite.setTexture(_textureMap[PickUpTextures::SKELETON]);
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
	_pickAnimation->Play(&_textureMap[PickUpTextures::PICK]);
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
