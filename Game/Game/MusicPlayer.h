#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H
#include "SFML\Audio.hpp"
#include <map>
#include <iostream>

namespace Music
{
	enum ID {MenuTheme, LevelTheme};
}

class MusicPlayer
{
public:
	MusicPlayer();
	~MusicPlayer();

	void Play(Music::ID theme);
	void Stop();
	void SetPaused(bool paused);
	void SetVolume(float volume);
private:
	sf::Music _music;
	std::map<Music::ID, std::string> _fileName;
	float _volume;

	const std::string MUSIC_PATH = "../Game/Assets/Music/";
};

#endif