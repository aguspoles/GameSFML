#pragma once
#include "Entity.h"
#include "Animation.h"

class PickUp :
	public Entity
{
private:
	static std::map<std::string, sf::Texture> _textureMap;
	static std::map<std::string, bool> _texturesLoaded;
	Animation* _pickAnimation;
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

