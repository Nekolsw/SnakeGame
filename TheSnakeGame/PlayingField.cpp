#include "PlayingField.h"
#include "Resources.h"
namespace SnakeGame
{
	void PlayingField::SetTextureSprite(sf::Texture textureCell, Field& field)
	{	
			cellTexture = textureCell; 
			for (int i = 0; i < CELL_FOR_WIDHT; ++i)
			{
				for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
				{
					field.cellField[i][j].spriteCell.setTexture(cellTexture);
				}
			}
	}

	void PlayingField::InitializingField(sf::Texture gameTextureCell, Field& field)
	{
		cellTexture = gameTextureCell;
		for (int i = 0; i < CELL_FOR_WIDHT; ++i)
		{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				field.cellField[i][j].cellPosition = { ((float)SIZE_CELL * i + FIELD_OFFSET_WIDTH), ((float)SIZE_CELL * j + FIELD_OFFSET_HEIGHT) };
				field.cellField[i][j].spriteCell.setTexture(cellTexture);
				SetSpriteSize(field.cellField[i][j].spriteCell, SIZE_CELL, SIZE_CELL);
				SetSpriteRelativeOrigin(field.cellField[i][j].spriteCell, 0.f, 0.f);
				field.cellField[i][j].spriteCell.setPosition(field.cellField[i][j].cellPosition.x, field.cellField[i][j].cellPosition.y);
				SetSpriteRelativeOrigin(field.cellField[i][j].spriteCell, 0.5f, 0.5f);
				field.cellField[i][j].itemType = ItemType::Null;
			}
		}
		field.cellField[(int)CELL_FOR_WIDHT / 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
		field.cellField[(int)CELL_FOR_WIDHT / 2 + 1][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
		field.cellField[(int)CELL_FOR_WIDHT / 2 + 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
	}

	void PlayingField::AddAppleForField(Apple& apple, Field& field)
	{
		PositionField positionApple;
		do
		{
			positionApple = GetRandomCellInGameScreen({ CELL_FOR_WIDHT, CELL_FOR_HEIGHT });
		}
		while (field.cellField[positionApple.cellWidth][positionApple.cellHeight].itemType != ItemType::Null);

		field.cellField[positionApple.cellWidth][positionApple.cellHeight].apple = &apple;
		field.cellField[positionApple.cellWidth][positionApple.cellHeight].apple->Spawn(field.cellField[positionApple.cellWidth][positionApple.cellHeight].cellPosition);
		field.cellField[positionApple.cellWidth][positionApple.cellHeight].itemType = ItemType::Apple;
		
	}

	void PlayingField::DeleteAppleForField(PositionField positionField, Field& field)
	{
		field.cellField[positionField.cellWidth][positionField.cellHeight].apple = nullptr;
		field.cellField[positionField.cellWidth][positionField.cellHeight].itemType = ItemType::Null;
	}

	void PlayingField::UpdateSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		for (PlayerSnake::PartSnake n : partSnake)
		{
			field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake = n;
			float widthPosition = n.positionSnake.cellWidth * SIZE_CELL + FIELD_OFFSET_WIDTH;
			float heightPosition = n.positionSnake.cellHeight * SIZE_CELL + FIELD_OFFSET_HEIGHT;
			field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake.spriteBody.setPosition({ widthPosition, heightPosition });
			field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].itemType = ItemType::PartSnake;
		}
	}

	void PlayingField::DeleteSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		for (PlayerSnake::PartSnake n : partSnake)
		{
			field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake = {};
			field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].itemType = ItemType::Null;
		}
	}

	void PlayingField::Draw(sf::RenderWindow& window, std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		for (int i = 0; i < CELL_FOR_WIDHT; ++i)
		{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				window.draw(field.cellField[i][j].spriteCell);
				if (field.cellField[i][j].apple != nullptr) 
				{
					field.cellField[i][j].apple->Draw(window);
				}
			}
		}
		for (PlayerSnake::PartSnake n : partSnake)
		{
			window.draw(field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake.spriteBody);
		}
	}
}