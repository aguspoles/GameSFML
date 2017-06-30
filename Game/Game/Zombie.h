#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Enemy.h"
#include "Animation.h"

namespace ZombieTextures
{
	enum TextureID { RUN };
}

class Zombie :
	public Enemy
{
private:
	float _elapsedSpeed;
	static const float Speed;
	bool _directionFlag, _isLookingRight;
	Animation* _runAnimation;

public:
	Zombie();
	Zombie(const sf::Vector2f& pos);
	~Zombie();

	static const std::string TEXTURES_PATH;
	static std::map<ZombieTextures::TextureID, sf::Texture> TextureMap;

	void Init();
	void Update();
	void Draw() const;
	void Move();
	void Animate();

};

#endif
