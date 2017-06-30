#ifndef SOUND_EFFECT_H
#define SOUND_EFFECT_H
#include "SFML\Audio.hpp"
#include <map>
#if DEBUG
#include <iostream>
#endif

class SoundEffect
{
private:
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	float _volume;

public:
	SoundEffect();
	~SoundEffect();

	void Play();
	void Stop();
	void SetPaused(bool paused);
	void SetVolume(float volume);
	void LoadSound(std::string path);
};

#endif

