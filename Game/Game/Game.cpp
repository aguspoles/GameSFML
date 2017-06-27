#include "Game.h"

sf::Clock Game::_clock = sf::Clock();
float Game::_gameDeltaTime = 0;

Game::Game() : _window(NULL), _currentState(NULL)
{
	_score = new Score();
}

Game::~Game()
{
	if (_currentState)
		delete _currentState;
	if (_score) delete _score;
}

void Game::SwitchState(Game* g)
{
	if (_currentState) 
		delete _currentState;
	_currentState = g;
	_currentState->SetWindow(_window);
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
	return _gameDeltaTime;
}

float Game::ElapsedTime()
{
	_gameDeltaTime = _clock.restart().asSeconds();
	return _gameDeltaTime;
}
