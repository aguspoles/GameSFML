#ifndef PICKUP_H
#define PICKUP_H
#include "Entity.h"
#include "Animation.h"
#include "SoundEffect.h"

namespace PickUpTextures
{
	enum TextureID { SKELETON, PICK };
}
namespace PickUpSound
{
	enum SoundID { PICK };
}

class PickUp :
	public Entity
{
private:
	static std::map<PickUpTextures::TextureID, sf::Texture> _textureMap;
	static std::map<PickUpTextures::TextureID, bool> _texturesLoaded;
	Animation* _pickAnimation;

	static std::map<PickUpSound::SoundID, SoundEffect> _soundMap;
	static bool _pickSoundLoaded;

	const std::string TEXTURES_PATH = "../Game/Assets/Textures/Skeleton/";
	const std::string SOUND_PATH = "../Game/Assets/";
public:
	PickUp();
	~PickUp();

	void Init();
	void Draw() const;
	void Update();
	void Animate();

	std::string GetType() const;
	Animation GetPickAnimation() const;
	SoundEffect* GetPickSound() const;
};

#endif