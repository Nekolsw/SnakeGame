#pragma once
#include <vector>
#include "GameObject.h"
#include "Resources.h"
namespace SnakeGame
{
	class Apple : public GameObject
	{
	private:
		enum AppleEffects
		{
			IncreaseSizeSnake = 0,
		};
	public:
		std::vector <AppleEffects> appleEffects;
		void Draw(sf::RenderWindow& window) override;
		void Spawn(Position2D GameObjectPosition) override;
		void Initialization(float sizeGameObject, sf::Texture gameObjectTexture) override;
		std::vector <AppleEffects> GetEffect();
	};
}