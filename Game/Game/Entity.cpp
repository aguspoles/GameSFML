#include "Entity.h"



Entity::Entity() : _window(NULL), _isVisible(true)
{

}

Entity::~Entity()
{
}

void Entity::SetWindow(sf::RenderWindow* window)
{
	_window = window;
}

sf::Sprite Entity::GetSprite() const
{
	return _sprite;
}

bool Entity::IsVisible() const
{
	return _isVisible;
}

