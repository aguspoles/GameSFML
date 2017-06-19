#include "Player.h"

std::map<std::string, sf::Texture> Player::_textureMap;
const float Player::Speed = 150;

Player::Player() : _movementSpeed(0), _isMoving(false), _isDestroy(false), 
_isFighting(false), _lookingRight(true)
{
	_sprite.setOrigin(283.5,278);
	_sprite.scale(sf::Vector2f(0.2, 0.2));
	_sprite.setPosition(50, 50);

	_textureMap["Idle"] = sf::Texture(); 
	_textureMap["Idle"].loadFromFile("../Game/Textures/Idle.png");
	_textureMap["Run"] = sf::Texture();
	_textureMap["Run"].loadFromFile("../Game/Textures/Run.png");
	_textureMap["Shoot"] = sf::Texture();
	_textureMap["Shoot"].loadFromFile("../Game/Textures/Shoot.png");

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
	_isMoving = false;
	if (_sprite.getPosition().x < (_window->getSize().x - _sprite.getGlobalBounds().width/2 + 30))
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

	if (_sprite.getPosition().x > (_sprite.getGlobalBounds().width / 2)-30)
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

	if (_sprite.getPosition().y < (_window->getSize().y - _sprite.getGlobalBounds().height/2 + 10))
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_sprite.move(0, _movementSpeed);
			_isMoving = true;
		}*/
		_sprite.move(0, _movementSpeed);
	}

	if (_sprite.getPosition().y > _sprite.getGlobalBounds().height/2 -10)
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
		_runAnimation->Play(&_textureMap["Run"]);
	}
	else if (_isFighting)
		_shootAnimation->Play(&_textureMap["Shoot"]);
	else
	{
		_idleAnimation->Play(&_textureMap["Idle"]);
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
		if (pickup->GetPickAnimation().Ended())
			pickup->SetVisible(false);
	}
}
