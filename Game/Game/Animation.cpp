#include "Animation.h"

Animation::Animation()
{
}


Animation::Animation(sf::Sprite* sprite, sf::Vector2i frameSize, std::size_t countFrames,
	float duration, bool repeat) : 
	_sprite(sprite),
	_frameSize(frameSize),
	_countFrames(countFrames),
	_duration(duration),
	_repeat(repeat),
	_elapsed(0),
	_currentFrame(0),
	_ended(false)
{
}

Animation::~Animation()
{
}

void Animation::Play(sf::Texture* texture)
{
	//cambio de textura solo si la que estaba es diferente
	if (_sprite->getTexture() != texture)
	{
		//vuelvo al primer frame de la imagen
		_currentFrame = 0;
		_sprite->setTexture(*texture);
	}

	//duracion de cada frame de la imagen
	float timePerFrame = _duration / static_cast<float>(_countFrames);
	//tiempo de la anterior iteracion del loop del juego
	_elapsed += Game::Time();
	sf::Vector2i textureBounds(_sprite->getTexture()->getSize());
	sf::IntRect texureRect = _sprite->getTextureRect();

	if (_currentFrame == 0)
		texureRect = sf::IntRect(0, 0, _frameSize.x, _frameSize.y);

	//si el tiempo de la anterior iteracion del loop del juego 
	//es menor que la duracion del frame de la imagen termino.
	//si recorri todos los frames de la imagen o si no se repite la animacion termino.
	while (_elapsed >= timePerFrame && (_currentFrame <= _countFrames || _repeat))
	{
		//std::cout << _currentFrame << std::endl;
		texureRect.left += texureRect.width;
		//si llego al final de la fila de frames, vuelvo a 0 y bajo una fila(aumento Y)
		if (texureRect.width + texureRect.left > textureBounds.x)
		{
			texureRect.left = 0;
			texureRect.top += texureRect.height;
		}
		//voy restando el tiempo del frame de la imagen
		_elapsed -= timePerFrame;

		if (_repeat)
		{
			//si llegue al ultimo frame de la imagen, comienzo nuevamente
			if ((_currentFrame + 1) % _countFrames == 0)
			{
				_currentFrame = 0;
				texureRect = sf::IntRect(0, 0, _frameSize.x, _frameSize.y);
				_ended = true;//si quiero saber cuando la animacion termino una iteracion
			}
			else
			{
				_currentFrame++;
			}
		}
	}
	//seteo el frame de la imagen al sprite
	_sprite->setTextureRect(texureRect);
}

bool Animation::Ended()
{
	return _ended;
}
