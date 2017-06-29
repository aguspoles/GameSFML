#include "MusicPlayer.h"


MusicPlayer::MusicPlayer() : _volume(100)
{
	_fileName[Music::MenuTheme] = MUSIC_PATH + "LevelTheme.wav";
	_fileName[Music::LevelTheme] = MUSIC_PATH + "LevelTheme.wav";
}


MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::Play(Music::ID theme)
{
	std::string fileName = _fileName[theme];
	if (!_music.openFromFile(fileName))
#ifdef DEBUG
			std::cout << "Music " + fileName + " cloud not be loaded.";
#endif

	_music.setVolume(_volume);
	_music.setLoop(true);
	_music.play();
}

void MusicPlayer::Stop()
{
	_music.stop();
}

void MusicPlayer::SetPaused(bool paused)
{
	if (paused) _music.pause();
	else _music.play();
}

void MusicPlayer::SetVolume(float volume)
{
	_music.setVolume(volume);
}
