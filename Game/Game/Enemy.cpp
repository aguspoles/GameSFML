#include "Enemy.h"



Enemy::Enemy()
{
}

Enemy::Enemy(const sf::Vector2f& pos)
{
	_sprite.setPosition(pos);
}

Enemy::Enemy(const sf::Vector2f& pos, const std::string& texture) : Entity()
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

void Enemy::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void Enemy::SetTexture(const std::string& texture)
{
	_texture.loadFromFile("../Game/Textures/Enemy/" + texture);
	_sprite.setTexture(_texture);
}

void Enemy::Move()
{
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
