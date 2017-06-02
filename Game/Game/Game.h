#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Enemy.h"
#include <list>
#include <time.h>

class Game
{
private:
	Game* _currentState;
protected:
	sf::RenderWindow* _window;
public:
	Game();
	virtual ~Game();

    virtual void Run() = 0;
	virtual void Update() = 0;
	virtual void Init() = 0;
	virtual void Destroy() = 0;

    void SwitchState(Game* g);
	Game* GetState() const;
	void SetWindow(sf::RenderWindow* window);
	sf::RenderWindow* GetWindow() const;
};

