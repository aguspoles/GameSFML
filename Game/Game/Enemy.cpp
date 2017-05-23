#include "Enemy.h"



Enemy::Enemy() : Entity()
{
}

Enemy::Enemy(sf::Vector2f pos) : Entity()
{
	_sprite.setPosition(pos);
}

Enemy::Enemy(sf::Vector2f pos, std::string texture) : Entity()
{
	_sprite.setScale(sf::Vector2f(2, 2));
	SetTexture(texture);
	_sprite.setPosition(pos);
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Move();
}

void Enemy::Draw()
{
	if (_window)
		_window->draw(_sprite);
}

void Enemy::SetTexture(std::string texture)
{
	_texture.loadFromFile("../Game/Textures/Enemy/" + texture);
	_sprite.setTexture(_texture);
}

void Enemy::Move()
{
}

std::string Enemy::GetType()
{
	return "Enemy";
}
