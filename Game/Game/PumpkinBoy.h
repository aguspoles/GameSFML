#ifndef PUMPKIN_BOY
#define PUMPKIN_BOY
#include "Enemy.h"

class PumpkinBoy :
	public Enemy
{
private:
	static std::map<std::string, sf::Texture> _textureMap;
	static std::map<std::string, bool> _texturesLoaded;//para saber si ya cargue la textura en _texturemap
	float _elapsedSpeed;
	static const float Speed;
	bool _directionFlag, _isLookingRight;
	Animation* _runAnimation;
public:
	PumpkinBoy();
	PumpkinBoy(const sf::Vector2f& pos);
	~PumpkinBoy();

	void Init();
	void Update();
	void Draw() const;
	void Move();
	void Animate();

	//std::string PumpkinBoy::GetType() const;
};

#endif
