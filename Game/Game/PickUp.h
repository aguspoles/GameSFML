#pragma once
#include "Entity.h"
#include "Animation.h"

namespace PickUpTextures
{
	enum TextureID { SKELETON, PICK };
}

class PickUp :
	public Entity
{
private:
	static std::map<PickUpTextures::TextureID, sf::Texture> _textureMap;
	static std::map<PickUpTextures::TextureID, bool> _texturesLoaded;
	Animation* _pickAnimation;

	const std::string TEXTURES_PATH = "../Game/Textures/";
public:
	PickUp();
	~PickUp();

	void Init();
	void Draw() const;
	void Update();
	void Animate();

	std::string GetType() const;
	Animation GetPickAnimation() const;
};

