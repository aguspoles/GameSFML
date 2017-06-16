#include "Enemy.h"



Enemy::Enemy() : flag(true), _movementSpeed(25)
{
}

Enemy::Enemy(const sf::Vector2f& pos) : flag(true), _movementSpeed(25)
{
	_sprite.setPosition(pos);
}

Enemy::Enemy(const sf::Vector2f& pos, const std::string& texture) : flag(true), _movementSpeed(25)
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
	_movementSpeed = Game::Time() * 25;
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
	if ((_sprite.getPosition().x < _window->getSize().x - _sprite.getGlobalBounds().width) && flag)
	{
			_sprite.move(_movementSpeed, 0);
	}
	else flag = false;
	if (_sprite.getPosition().x > 0 && !flag)
	{
			_sprite.move(-_movementSpeed, 0);
	}
	else flag = true;
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
