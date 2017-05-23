#pragma once
#include "Entity.h"
#include "Enemy.h"

class Player :
	public Entity
{
private:
	float _movementSpeed = 0.1;
	bool _isMoving;
	bool _isFighting;
	bool _isDestroy;

public:
	Player();
	Player(std::string texture);
	~Player();

	void Update();
	void Draw();
	void SetTexture(std::string texture);
	void Move();
	void Fight();
	void Animate();

	std::string GetType();
	void IdleAnimation();
	void MovementAnimation();
	void MeleeAnimation();
	bool IsMoving();

	void PlayerCollision(std::list<Entity*> &entities);
};

