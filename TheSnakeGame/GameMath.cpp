#include <SFML/Graphics.hpp>
#include "GameMath.h"
#include "PlayingField.h"

namespace SnakeGame
{
	PositionField GetRandomCellInGameScreen(PositionField positionField)
	{
		PositionField result;
		result.cellWidth = rand() & (positionField.cellWidth - 1);
		result.cellHeight = rand() & (positionField.cellHeight - 1);
		return result;
	}

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidth, float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	sf::Vector2f ConversionPositionCellsInScreenPosition (PositionField positionField) 
	{
		return { float(positionField.cellWidth * CELL_FOR_WIDHT + FIELD_OFFSET_WIDTH), float(positionField.cellHeight * CELL_FOR_HEIGHT + FIELD_OFFSET_HEIGHT) };
	}
}