#include "Player.h"

Player::Player() : _movementSpeed(0.1), _isMoving(false), _isDestroy(false), _isFighting(false)
{
	_sprite.scale(sf::Vector2f(0.2, 0.2));
}

Player::Player(const std::string& texture) : _movementSpeed(0.1), _isMoving(false), _isDestroy(false), _isFighting(false)
{
	_sprite.scale(sf::Vector2f(0.2, 0.2));
	SetTexture(texture);
}


Player::~Player()
{
}

void Player::Update()
{
	_movementSpeed = Game::Time()  * 0.1;
	Move();
	Fight();
	Animate();
}

void Player::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void Player::SetTexture(const std::string& texture)
{
	_texture.loadFromFile("../Game/Textures/Player/" + texture);
	_sprite.setTexture(_texture);
}

void Player::Move()
{
	_isMoving = false;
	if (_sprite.getPosition().x < (_window->getSize().x - _sprite.getGlobalBounds().width + 90))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_sprite.move(_movementSpeed, 0);
			_isMoving = true;
		}
	}

	if (_sprite.getPosition().x > -80)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_sprite.move(-_movementSpeed, 0);
			_isMoving = true;
		}
	}

	if (_sprite.getPosition().y < (_window->getSize().y - _sprite.getGlobalBounds().height + 20))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_sprite.move(0, _movementSpeed);
			_isMoving = true;
		}
	}

	if (_sprite.getPosition().y > -20)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_sprite.move(0, -_movementSpeed);
			_isMoving = true;
		}
	}
}

void Player::Fight() 
{
	_isFighting = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		_isFighting = true;
}

void Player::Animate()
{
	if (_isMoving)
		MovementAnimation();
	else if (_isFighting)
		MeleeAnimation();
    else IdleAnimation();
}

std::string Player::GetType() const
{
	return "Player";
}

void Player::IdleAnimation()
{
	static int time = 1;
	static sf::Clock _clock;
	if (Game::Time() >= time*0.1)
	{
		std::string iesimo = "Idle ";
		iesimo += "(";
		iesimo += std::to_string(time);
		iesimo += ").png";
		SetTexture(iesimo);
		time++;
	}

	if (time == 10)
	{
		_clock.restart();
		time = 1;
	}
}

void Player::MovementAnimation()
{
	static int time = 1;
	static sf::Clock _clock;
	if (_clock.getElapsedTime().asSeconds() >= time*0.1)
	{
		std::string iesimo = "Run ";
		iesimo += "(";
		iesimo += std::to_string(time);
		iesimo += ").png";
		SetTexture(iesimo);
		time++;
	}

	if (time == 8)
	{
		_clock.restart();
		time = 1;
	}
}

void Player::MeleeAnimation()
{
	static int time = 1;
	static sf::Clock _clock;
	if (_clock.getElapsedTime().asSeconds() >= time*0.05)
	{
		std::string iesimo = "Shoot ";
		iesimo += "(";
		iesimo += std::to_string(time);
		iesimo += ").png";
		SetTexture(iesimo);
		time++;
	}

	if (time >= 5)
	{
		_clock.restart();
		time = 1;
	}
}

void Player::PlayerCollision(const std::list<Entity*> &entities)
{
	for each(Entity* entitie in entities)
	{
		if (entitie->GetType() == "Enemy")
		{
			if (_sprite.getGlobalBounds().intersects(entitie->GetSprite().getGlobalBounds()))
			{
				_isVisible = false;
			}
		}
	}
}
