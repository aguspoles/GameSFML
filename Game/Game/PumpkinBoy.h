#ifndef PUMPKIN_BOY
#define PUMPKIN_BOY
#include "Enemy.h"

namespace PumpKinTextures
{
	enum TextureID { RUN };
}

class PumpkinBoy :
	public Enemy
{
private:
	float _elapsedSpeed;
	static const float Speed;
	bool _directionFlag, _isLookingRight;
	Animation* _runAnimation;

public:
	PumpkinBoy();
	PumpkinBoy(const sf::Vector2f& pos);
	~PumpkinBoy();

	static const std::string TEXTURES_PATH;
	static std::map<PumpKinTextures::TextureID, sf::Texture> TextureMap;

	void Init();
	void Update();
	void Draw() const;
	void Move();
	void Animate();

	//std::string PumpkinBoy::GetType() const;
};

#endif
