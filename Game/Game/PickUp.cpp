#include "PickUp.h"

std::map<PickUpAssets::TextureID, sf::Texture> PickUp::TextureMap;
std::map<PickUpAssets::SoundID, SoundEffect> PickUp::SoundMap;
const std::string PickUp::TEXTURES_PATH = "../Assets/Textures/Skeleton/";
const std::string PickUp::SOUND_PATH = "../Assets/Sounds/";

PickUp::PickUp()
{
	_sprite.setOrigin(51, 25);
	_sprite.scale(0.5, 0.5);
	_sprite.setPosition(150, 50);

	_pickAnimation = new Animation(&_sprite, sf::Vector2i(128, 128), 4, 1, true);

	_sprite.setTexture(TextureMap[PickUpAssets::SKELETON]);

	SoundMap[PickUpAssets::PICKSOUND].SetVolume(50);
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
	_sprite.rotate(Game::Time()*90);
}

void PickUp::Animate()
{
	_pickAnimation->Play(&TextureMap[PickUpAssets::PICK]);
	_sprite.rotate(Game::Time()*500);
}

std::string PickUp::GetType() const
{
	return "PickUp";
}

Animation PickUp::GetPickAnimation() const
{
	return *_pickAnimation;
}

SoundEffect* PickUp::GetPickSound() const
{
	return &SoundMap[PickUpAssets::PICKSOUND];
}
