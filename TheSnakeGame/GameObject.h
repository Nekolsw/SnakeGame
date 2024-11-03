#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameMath.h"

namespace SnakeGame
{
	class GameObject
	{
		protected:
			sf::Sprite sprite;
			sf::Texture texture;
		public:
			float size = 12;
			Position2D position = { 0.f, 0.f };

			// Initialization and spawn object in game 
			virtual void Initialization(float sizeGameObject, sf::Texture gameObjectTexture) = 0;

			virtual void Spawn(Position2D GameObjectPosition) = 0;

			virtual void Draw(sf::RenderWindow& window) = 0;
	};
}