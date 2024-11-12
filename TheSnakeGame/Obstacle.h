#pragma once
#include "GameObject.h"
#include "Resources.h"
namespace SnakeGame
{
	class Obstacle : public GameObject
	{
	public:
		void Draw(sf::RenderWindow& window) override;
		void Spawn(Position2D GameObjectPosition) override;
		void Initialization(float sizeGameObject, sf::Texture gameObjectTexture) override;

	};
}

