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

sf::Sprite* Entity::GetSprite()
{
	return &_sprite;
}

bool Entity::IsVisible() const
{
	return _isVisible;
}

void Entity::SetVisible(bool is)
{
	_isVisible = is;
}

