#include "Enemy.h"


Enemy::Enemy() 
{

}

Enemy::Enemy(const sf::Vector2f& pos)
{
	_sprite.setPosition(pos);
}

Enemy::~Enemy()
{
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
