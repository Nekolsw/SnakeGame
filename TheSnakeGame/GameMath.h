#pragma once

namespace sf
{
	class sprite;
}
namespace SnakeGame
{
	struct Position2D
	{
		float x = 0, y = 0;
	};

	struct PositionField
	{
		int cellWidth = 0, cellHeight = 0;
	};

	PositionField GetRandomCellInGameScreen(PositionField positionField);

	void SetSpriteSize(sf::Sprite& sprite, float desireWidth, float desiredHeight);

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY);

	sf::Vector2f ConversionPositionCellsInScreenPosition(PositionField positionField);

}
