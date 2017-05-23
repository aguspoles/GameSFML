#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
private:
	float _movementSpeed = 0.1;
public:
	Enemy();
	Enemy(sf::Vector2f pos);
	Enemy(sf::Vector2f pos, std::string textura);
	~Enemy();

	void Update();
	void Draw();
	void SetTexture(std::string texture);
	void Move();

	std::string GetType();
};

