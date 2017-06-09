#include "Game.h"

sf::Clock Game::_clock = sf::Clock();
float Game::_elapsed = 0;

Game::Game() : _window(NULL), _currentState(NULL)
{

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

float Game::Time()
{
	return _clock.getElapsedTime().asSeconds();
}

float Game::ElapsedTime()
{
	_elapsed = _clock.restart().asSeconds();
	return _elapsed;
}
