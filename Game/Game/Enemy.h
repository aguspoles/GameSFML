#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
private:
	float _movementSpeed = 0.1;
public:
	Enemy();
	Enemy(const sf::Vector2f& pos);
	Enemy(const sf::Vector2f& pos, const std::string& textura);
	~Enemy();

	void Update();
	void Draw() const;
	void SetTexture(const std::string& texture);
	void Move();

	std::string GetType() const;
};

