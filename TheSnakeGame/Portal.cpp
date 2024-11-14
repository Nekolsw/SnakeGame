#include "Portal.h"
namespace SnakeGame
{
	void Portal::Initialization(float sizeGameObject, sf::Texture gameObjectTexture)
	{
		size = sizeGameObject;
		texture = gameObjectTexture;
		texture.setSmooth(true);
		Spawn(position);
	}

	void Portal::Spawn(Position2D GameObjectPosition)
	{
		position = GameObjectPosition;
		sprite.setTexture(texture);
		SetSpriteSize(sprite, size, size);
		sprite.setPosition({ position.x, position.y });
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}

	void Portal::Draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}
}