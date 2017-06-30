#include "Player.h"

std::map<PlayerTextures::TextureID, sf::Texture> Player::TextureMap;
const std::string Player::TEXTURES_PATH = "Assets/Textures/Player/";
const float Player::Speed = 130;

Player::Player() : _movementSpeed(0), _isMoving(false), _isDestroy(false), 
_isFighting(false), _lookingRight(true)
{
	_sprite.setOrigin(283.5,278);
	_sprite.scale(sf::Vector2f(0.15, 0.15));
	_sprite.setPosition(50, 50);

	_runAnimation = new Animation(&_sprite, sf::Vector2i(567, 556), 8, 0.5, true);
	_idleAnimation = new Animation(&_sprite, sf::Vector2i(567, 556), 10, 1, true);
	_shootAnimation = new Animation(&_sprite, sf::Vector2i(567, 556), 4, 0.2, true);
}

Player::Player(const std::string& texture) : _movementSpeed(0), _isMoving(false), _isDestroy(false), 
                                             _isFighting(false)
{
	_sprite.setOrigin(283.5, 278);
	_sprite.scale(sf::Vector2f(0.2, 0.2));
	_sprite.setPosition(50, 50);
}


Player::~Player()
{
	if (_idleAnimation) delete _idleAnimation;
	if (_runAnimation) delete _runAnimation;
	if (_shootAnimation) delete _shootAnimation;
}

void Player::Init()
{
}

void Player::Update()
{
	_movementSpeed = Game::Time()  * Speed;
	Move();
	Fight();
	Animate();
}

void Player::Draw() const
{
	if (_window)
		_window->draw(_sprite);
}

void Player::Move()
{
	float spriteWith = _sprite.getGlobalBounds().width / 2;
	float spriteHeight = _sprite.getGlobalBounds().height / 2;
	float windowWith = _window->getSize().x;
	float windowHeight = _window->getSize().y;
	_isMoving = false;

	if (_sprite.getPosition().x < (windowWith - spriteWith+30))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_sprite.move(_movementSpeed,0);
			if (!_lookingRight)
			{
				_sprite.scale(-1, 1);
				_lookingRight = true;
			}
			_isMoving = true;
		}
	}

	if (_sprite.getPosition().x > spriteWith-30)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_sprite.move(-_movementSpeed, 0);;
			if (_lookingRight)
			{
				_sprite.scale(-1, 1);
				_lookingRight = false;
			}
			_isMoving = true;
		}
	}

	if (_sprite.getPosition().y < (windowHeight - spriteHeight + 10))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_sprite.move(0, _movementSpeed);
			_isMoving = true;
		}
		//_sprite.move(0, _movementSpeed);//gravity
	}

	if (_sprite.getPosition().y > spriteHeight -10)
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
	{
		_runAnimation->Play(&TextureMap[PlayerTextures::RUN]);
	}
	else if (_isFighting)
		_shootAnimation->Play(&TextureMap[PlayerTextures::SHOOT]);
	else
	{
		_idleAnimation->Play(&TextureMap[PlayerTextures::IDLE]);
	}
}

std::string Player::GetType() const
{
	return "Player";
}

void Player::PlayerCollision(std::list<Entity*> &entities)
{
	for(std::list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		if (*it && (*it)->IsVisible())
		{
			if ((*it)->GetType() == "Enemy")
			{
				Enemy *e = (Enemy*)*it;
				Collide(e);
			}
			if ((*it)->GetType() == "PickUp")
			{
				PickUp *p = (PickUp*)*it;
				Collide(p);
			}
		}
	}
}

void Player::Collide(Enemy * enemy)
{
	if (_sprite.getGlobalBounds().intersects(enemy->GetSprite()->getGlobalBounds()))
	{
		_isVisible = false;
	}
}

void Player::Collide(PickUp * pickup)
{
	if (_sprite.getGlobalBounds().intersects(pickup->GetSprite()->getGlobalBounds()))
	{
		pickup->Animate();
		pickup->GetPickSound()->Play();
		if (pickup->GetPickAnimation().Ended())
		{
			pickup->SetVisible(false);
		    Score::PickUpsLeft--;
		}
		Score::SCORE += 5;
	}
}
