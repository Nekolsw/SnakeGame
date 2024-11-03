#include "Apple.h"

namespace SnakeGame 
{
	void Apple::Initialization(float sizeGameObject, sf::Texture gameObjectTexture)
	{
		size = sizeGameObject;
		texture = gameObjectTexture;
		texture.setSmooth(true);
		appleEffects.resize(MAX_EFFECT_APPLE);
		Spawn(position);
	}

	std::vector <Apple::AppleEffects> Apple::GetEffect()
	{
		return appleEffects;
	}

	void Apple::Spawn(Position2D GameObjectPosition)
	{
		position = GameObjectPosition;
		sprite.setTexture(texture);
		SetSpriteSize(sprite, size, size);
		sprite.setPosition({ position.x, position.y });
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}

	void Apple::Draw(sf::RenderWindow& window)
	{
			window.draw(sprite);
	}
}