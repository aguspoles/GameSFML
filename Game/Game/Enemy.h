#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include "Game.h"
#include "Animation.h"

class Enemy :
	public Entity
{
private:


public:
	Enemy();
	Enemy(const sf::Vector2f& pos);
	virtual ~Enemy();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Move() = 0;
	virtual void Animate() = 0;

	std::string GetType() const;
};

#endif