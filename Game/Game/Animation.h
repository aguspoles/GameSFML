#ifndef ANIMATION_H
#define ANIMATION_H
#include "Game.h"

class Animation
{
private:
	sf::Sprite* _sprite; //puntero a sprite de la entidad
	sf::Vector2i _frameSize;
	std::size_t _countFrames;
	std::size_t _currentFrame;
	float _elapsed;
	float _duration;
	bool _repeat;

	bool _ended;//si termino la animacion
public:
	Animation();
	Animation(sf::Sprite* sprite, sf::Vector2i frameSize, std::size_t countFrames,
		float duration, bool repeat);
	~Animation();

	void Play(sf::Texture* texture);
	bool Ended();
};

#endif

