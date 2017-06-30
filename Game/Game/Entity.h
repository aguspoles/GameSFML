#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include<string>
#include <list>
#include <map>
#if DEBUG
#include <iostream>
#endif

class Entity
{
protected:
	sf::Sprite _sprite;
	sf::RenderWindow* _window;
	bool _isVisible;
public:
	Entity();
	virtual ~Entity();

	virtual void Init() = 0;
	virtual void Draw() const = 0;
	virtual void Update() = 0;
	void SetWindow(sf::RenderWindow* window);

	sf::Sprite* GetSprite();
	virtual std::string GetType() const = 0;
	bool IsVisible() const;
	void SetVisible(bool is);
};

#endif