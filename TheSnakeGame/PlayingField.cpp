#include "PlayingField.h"
#include "Resources.h"
namespace SnakeGame
{
	void PlayingField::SetTextureSprite(sf::Texture textureCell, Field& field)
	{	
			cellTexture = textureCell; 
			for (int i = 0; i < CELL_FOR_WIDTH; ++i)
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
		for (int i = 0; i < CELL_FOR_WIDTH; ++i)
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
		field.cellField[(int)CELL_FOR_WIDTH / 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::HeadSnake;
		field.cellField[(int)CELL_FOR_WIDTH / 2 + 1][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
		field.cellField[(int)CELL_FOR_WIDTH / 2 + 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
	}

	void PlayingField::ReloadField(Field& field)
	{
		for (int i = 0; i < CELL_FOR_WIDTH; ++i)
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
		field.cellField[(int)CELL_FOR_WIDTH / 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::HeadSnake;
		field.cellField[(int)CELL_FOR_WIDTH / 2 + 1][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
		field.cellField[(int)CELL_FOR_WIDTH / 2 + 2][(int)CELL_FOR_HEIGHT / 2].itemType = ItemType::PartSnake;
	}

	void PlayingField::AddAppleForField(Apple& apple, Field& field)
	{
		PositionField positionApple;
		do
		{
			positionApple = GetRandomCellInGameScreen({ CELL_FOR_WIDTH, CELL_FOR_HEIGHT });
		}
		while (field.cellField[positionApple.cellWidth][positionApple.cellHeight].itemType != ItemType::Null);

		field.cellField[positionApple.cellWidth][positionApple.cellHeight].apple = &apple;
		field.cellField[positionApple.cellWidth][positionApple.cellHeight].apple->Spawn(field.cellField[positionApple.cellWidth][positionApple.cellHeight].cellPosition);
		field.cellField[positionApple.cellWidth][positionApple.cellHeight].itemType = ItemType::Apple;
		
	}

	void PlayingField::AddObstacleForField(Obstacle obstacle, Field& field)
	{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				field.cellField[0][j].obstacle = obstacle;
				field.cellField[0][j].obstacle.Spawn(field.cellField[0][j].cellPosition);
				field.cellField[0][j].itemType = ItemType::Obstacle;
			}
			for (int j = 0; j < CELL_FOR_WIDTH; ++j)
			{
				field.cellField[j][0].obstacle = obstacle;
				field.cellField[j][0].obstacle.Spawn(field.cellField[j][0].cellPosition);
				field.cellField[j][0].itemType = ItemType::Obstacle;
			}	
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				field.cellField[14][j].obstacle = obstacle;
				field.cellField[14][j].obstacle.Spawn(field.cellField[14][j].cellPosition);
				field.cellField[14][j].itemType = ItemType::Obstacle;
			}
			for (int j = 0; j < CELL_FOR_WIDTH; ++j)
			{
				field.cellField[j][7].obstacle = obstacle;
				field.cellField[j][7].obstacle.Spawn(field.cellField[j][7].cellPosition);
				field.cellField[j][7].itemType = ItemType::Obstacle;
			}
	}

	void PlayingField::DeleteAppleForField(PositionField positionField, Field& field)
	{
		field.cellField[positionField.cellWidth][positionField.cellHeight].apple = nullptr;
		field.cellField[positionField.cellWidth][positionField.cellHeight].itemType = ItemType::Null;
	}

	void PlayingField::UpdateSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		std::list <PlayerSnake::PartSnake> ::iterator n;
		for (n = ++partSnake.begin(); n != partSnake.end(); n++)
		{

				field.cellField[n->positionSnake.cellWidth][n->positionSnake.cellHeight].bodySnake = *n;
				float widthPosition = n->positionSnake.cellWidth * SIZE_CELL + FIELD_OFFSET_WIDTH;
				float heightPosition = n->positionSnake.cellHeight * SIZE_CELL + FIELD_OFFSET_HEIGHT;
				field.cellField[n->positionSnake.cellWidth][n->positionSnake.cellHeight].bodySnake.spriteBody.setPosition({ widthPosition, heightPosition });
				field.cellField[n->positionSnake.cellWidth][n->positionSnake.cellHeight].itemType = ItemType::PartSnake;
			}
		if (field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].itemType != ItemType::PartSnake)
		{
			field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].bodySnake = partSnake.front();
			float widthPosition = partSnake.front().positionSnake.cellWidth * SIZE_CELL + FIELD_OFFSET_WIDTH;
			float heightPosition = partSnake.front().positionSnake.cellHeight * SIZE_CELL + FIELD_OFFSET_HEIGHT;
			field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].bodySnake.spriteBody.setPosition({ widthPosition, heightPosition });
			field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].itemType = ItemType::HeadSnake;
		}
		else 
		{
			field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].itemType = ItemType::PartSnake;
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
		for (int i = 0; i < CELL_FOR_WIDTH; ++i)
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
		for (int i = 0; i < CELL_FOR_WIDTH; ++i)
		{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				if (field.cellField[i][j].itemType == ItemType::Obstacle)
				{
					field.cellField[i][j].obstacle.Draw(window);
				}
			}
		}
		for (PlayerSnake::PartSnake n : partSnake)
		{
				window.draw(field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake.spriteBody);
		}
	}
}