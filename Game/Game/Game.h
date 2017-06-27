#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <time.h>
#include "Score.h"

class Game
{
private:
	Game* _currentState;
	static sf::Clock _clock;
    static float _gameDeltaTime;
protected:
	sf::RenderWindow* _window;
public:
	Game();
	virtual ~Game();

    virtual void Run() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Init() = 0;
	virtual void Destroy() = 0;

    void SwitchState(Game* g);
	Game* GetState() const;
	void SetWindow(sf::RenderWindow* window);
	sf::RenderWindow* GetWindow() const;

	static float Time();
	static float ElapsedTime();
};

#endif