#include "Game.h"

Game::Game()
{
	_window = NULL;
	_currentState = NULL;
}

Game::~Game()
{
	if (_currentState)
		delete _currentState;
}

void Game::SwitchState(Game* g)
{
	sf::RenderWindow* window = GetWindow();
	if (_currentState) 
		delete _currentState;
	_currentState = g;
	_currentState->SetWindow(window);
	_currentState->Run();
}

Game* Game::GetState() const
{
	return _currentState;
}

void Game::SetWindow(sf::RenderWindow* window)
{
	_window = window;
}

sf::RenderWindow* Game::GetWindow() const
{
	return _window;
}
