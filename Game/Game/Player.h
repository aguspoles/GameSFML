#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"
#include "PumpkinBoy.h"
#include "Entity.h"
#include "Animation.h"
#include "PickUp.h"
#if DEBUG
#include <iostream>
#endif

class Player :
	public Entity
{
private:
	static std::map<std::string, sf::Texture> _textureMap;
	static const float Speed;
	float _movementSpeed;
	bool _isMoving;
	bool _isFighting;
	bool _isDestroy;
	bool _lookingRight;
	Animation* _idleAnimation;
	Animation* _runAnimation;
	Animation* _shootAnimation;

public:
	Player();
	Player(const std::string& texture);
	~Player();

	void Init();
	void Update();
	void Draw() const;

	void Move();
	void Fight();
	void Animate();

	std::string GetType() const;
	bool IsMoving() const;

	void PlayerCollision(std::list<Entity*> &entities);
	void Collide(Enemy* enemy);
	void Collide(PickUp* pickup);
};

#endif