#ifndef PICKUP_H
#define PICKUP_H
#include "Entity.h"
#include "Animation.h"
#include "SoundEffect.h"

namespace PickUpAssets
{
	enum TextureID { SKELETON, PICK };
	enum SoundID { PICKSOUND };
}

class PickUp :
	public Entity
{
private:
    Animation* _pickAnimation;

public:
	PickUp();
	~PickUp();

	static std::map<PickUpAssets::TextureID, sf::Texture> TextureMap;
	static std::map<PickUpAssets::SoundID, SoundEffect> SoundMap;
	static const std::string TEXTURES_PATH;
	static const std::string SOUND_PATH;

	void Init();
	void Draw() const;
	void Update();
	void Animate();

	std::string GetType() const;
	Animation GetPickAnimation() const;
	SoundEffect* GetPickSound() const;
};

#endif