#include "SoundEffect.h"



SoundEffect::SoundEffect() : _volume(100)
{

}


SoundEffect::~SoundEffect()
{
}

void SoundEffect::Play()
{
	_sound.setVolume(_volume);
	_sound.play();
}

void SoundEffect::Stop()
{
	_sound.stop();
}

void SoundEffect::SetPaused(bool paused)
{
	if (paused) _sound.pause();
	else _sound.play();
}

void SoundEffect::SetVolume(float volume)
{
	_volume = volume;
}

void SoundEffect::LoadSound(std::string path)
{
	if (!_buffer.loadFromFile(path))
	{
#ifdef DEBUG
			std::cerr << "Sound " + path + " cloud not be loaded.";
#endif
	}
	else
		_sound.setBuffer(_buffer);
}
