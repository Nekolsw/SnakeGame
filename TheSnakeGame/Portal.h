#pragma once
#include "GameObject.h"
#include "Resources.h"
#include "GameMath.h"
namespace SnakeGame
{
	class Portal : public GameObject
	{
	public:
		PositionField portalPosition;
		Portal* linkPortal = nullptr;
		void Draw(sf::RenderWindow& window) override;
		void Spawn(Position2D GameObjectPosition) override;
		void Initialization(float sizeGameObject, sf::Texture gameObjectTexture) override;

	};
}
