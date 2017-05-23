#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>

class Entity
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::RenderWindow* _window;
	bool _isVisible;
public:
	Entity();
	virtual ~Entity();

	virtual void Draw() = 0;
	virtual void SetTexture(std::string texture) = 0;
	virtual void Update() = 0;
	void SetWindow(sf::RenderWindow* window);

	sf::Sprite GetSprite();
	virtual std::string GetType()=0;
	bool IsVisible();
};

