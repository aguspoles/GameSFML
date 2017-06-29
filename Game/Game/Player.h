#ifndef PLAYER_H
#define PLAYER_H
#include "Game.h"
#include "PumpkinBoy.h"
#include "Entity.h"
#include "Animation.h"
#include "PickUp.h"
#include "Score.h"
#if DEBUG
#include <iostream>
#endif

namespace PlayerTextures
{
	enum TextureID{IDLE, RUN, SHOOT};
}

class Player :
	public Entity
{
private:
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

	static std::map<PlayerTextures::TextureID, sf::Texture> TextureMap;
	static const std::string TEXTURES_PATH;

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