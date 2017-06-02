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
	Player(const std::string& texture);
	~Player();

	void Update();
	void Draw() const;
	void SetTexture(const std::string& texture);
	void Move();
	void Fight();
	void Animate();

	std::string GetType() const;
	void IdleAnimation();
	void MovementAnimation();
	void MeleeAnimation();
	bool IsMoving() const;

	void PlayerCollision(const std::list<Entity*> &entities);
};

