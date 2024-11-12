#include "Obstacle.h"
namespace SnakeGame
{
	void Obstacle::Initialization(float sizeGameObject, sf::Texture gameObjectTexture)
	{
		size = sizeGameObject;
		texture = gameObjectTexture;
		texture.setSmooth(true);
		Spawn(position);
	}

	void Obstacle::Spawn(Position2D GameObjectPosition)
	{
		position = GameObjectPosition;
		sprite.setTexture(texture);
		SetSpriteSize(sprite, size, size);
		sprite.setPosition({ position.x, position.y });
		SetSpriteRelativeOrigin(sprite, 0.5f, 0.5f);
	}

	void Obstacle::Draw(sf::RenderWindow& window)
	{
		window.draw(sprite);
	}
}