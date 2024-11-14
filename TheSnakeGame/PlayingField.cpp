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

	void PlayingField::AddPortalForField(Portal& portal_1, Portal& portal_2, Field& field)
	{
		PositionField positionPortal_1, positionPortal_2;
		do
		{
			positionPortal_1 = GetRandomCellInGameScreen({ CELL_FOR_WIDTH, CELL_FOR_HEIGHT });
		} while (field.cellField[positionPortal_1.cellWidth][positionPortal_1.cellHeight].itemType != ItemType::Null);
		do
		{
			positionPortal_2 = GetRandomCellInGameScreen({ CELL_FOR_WIDTH, CELL_FOR_HEIGHT });
		} while (field.cellField[positionPortal_2.cellWidth][positionPortal_2.cellHeight].itemType != ItemType::Null);

		portal_1.portalPosition = positionPortal_1;
		portal_2.portalPosition = positionPortal_2;
		field.cellField[positionPortal_1.cellWidth][positionPortal_1.cellHeight].portal_1 = &portal_1;
		field.cellField[positionPortal_2.cellWidth][positionPortal_2.cellHeight].portal_2 = &portal_2;
		field.cellField[positionPortal_1.cellWidth][positionPortal_1.cellHeight].portal_1->Spawn(field.cellField[positionPortal_1.cellWidth][positionPortal_1.cellHeight].cellPosition);
		field.cellField[positionPortal_2.cellWidth][positionPortal_2.cellHeight].portal_2->Spawn(field.cellField[positionPortal_2.cellWidth][positionPortal_2.cellHeight].cellPosition);
		field.cellField[positionPortal_1.cellWidth][positionPortal_1.cellHeight].itemType = ItemType::Portal_1;
		field.cellField[positionPortal_2.cellWidth][positionPortal_2.cellHeight].itemType = ItemType::Portal_2;
	}

	void PlayingField::AddRandomObstacleForField(Obstacle& obstacle, Field& field, GameSettings& gameSettings)
	{
		PositionField positionObstacle;
		int i = 0;
		while (i != NUMBER_RANDOM_OBSTACLE + static_cast<int>(gameSettings.difficultyGame)) 
		{
			do
			{
				positionObstacle = GetRandomCellInGameScreen({ CELL_FOR_WIDTH, CELL_FOR_HEIGHT });
			} while (field.cellField[positionObstacle.cellWidth][positionObstacle.cellHeight].itemType != ItemType::Null);

			field.cellField[positionObstacle.cellWidth][positionObstacle.cellHeight].obstacle = obstacle;
			field.cellField[positionObstacle.cellWidth][positionObstacle.cellHeight].obstacle.Spawn(field.cellField[positionObstacle.cellWidth][positionObstacle.cellHeight].cellPosition);
			field.cellField[positionObstacle.cellWidth][positionObstacle.cellHeight].itemType = ItemType::Obstacle;
			++i;
		}

	}

	void PlayingField::AddBorderObstacleForField(Obstacle& obstacle, Field& field)
	{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				field.cellField[0][j].obstacle = obstacle;
				field.cellField[0][j].obstacle.Spawn(field.cellField[0][j].cellPosition);
				field.cellField[0][j].itemType = ItemType::ObstacleBorder;
			}
			for (int j = 0; j < CELL_FOR_WIDTH; ++j)
			{
				field.cellField[j][0].obstacle = obstacle;
				field.cellField[j][0].obstacle.Spawn(field.cellField[j][0].cellPosition);
				field.cellField[j][0].itemType = ItemType::ObstacleBorder;
			}	
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				field.cellField[14][j].obstacle = obstacle;
				field.cellField[14][j].obstacle.Spawn(field.cellField[14][j].cellPosition);
				field.cellField[14][j].itemType = ItemType::ObstacleBorder;
			}
			for (int j = 0; j < CELL_FOR_WIDTH; ++j)
			{
				field.cellField[j][7].obstacle = obstacle;
				field.cellField[j][7].obstacle.Spawn(field.cellField[j][7].cellPosition);
				field.cellField[j][7].itemType = ItemType::ObstacleBorder;
			}
	}
	

	void PlayingField::DeleteObstacleForField(Field& field)
	{
		for (int i = 0; i < CELL_FOR_WIDTH; ++i)
		{
			for (int j = 0; j < CELL_FOR_HEIGHT; ++j)
			{
				if (field.cellField[i][j].itemType == ItemType::Obstacle)
					field.cellField[i][j].itemType = ItemType::Null;
			}
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

	void PlayingField::SnakeTeleportationIn_1(std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		switch (partSnake.front().snakePartDirection)
		{
		case PlayerSnake::SnakeDirection::Left:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellWidth - 1, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellHeight };
			break;
		case PlayerSnake::SnakeDirection::Right:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellWidth + 1, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellHeight };
			break;
		case PlayerSnake::SnakeDirection::Up:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellWidth, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellHeight - 1 };
			break;
		case PlayerSnake::SnakeDirection::Down:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellWidth, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_1->linkPortal->portalPosition.cellHeight + 1 };
			break;
		default:
			break;
		}

	}
	void PlayingField::SnakeTeleportationIn_2(std::list<PlayerSnake::PartSnake>& partSnake, Field& field)
	{
		switch (partSnake.front().snakePartDirection)
		{
		case PlayerSnake::SnakeDirection::Left:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellWidth - 1, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellHeight };
			break;
		case PlayerSnake::SnakeDirection::Right:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellWidth + 1, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellHeight };
			break;
		case PlayerSnake::SnakeDirection::Up:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellWidth, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellHeight - 1 };
			break;
		case PlayerSnake::SnakeDirection::Down:
			partSnake.front().positionSnake = { field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellWidth, field.cellField[partSnake.front().positionSnake.cellWidth][partSnake.front().positionSnake.cellHeight].portal_2->linkPortal->portalPosition.cellHeight + 1 };
			break;
		default:
			break;
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

	void PlayingField::Draw(sf::RenderWindow& window, std::list<PlayerSnake::PartSnake>& partSnake, Field& field, GameSettings& gameSettings)
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
				if (field.cellField[i][j].itemType == ItemType::ObstacleBorder || field.cellField[i][j].itemType == ItemType::Obstacle)
				{
					field.cellField[i][j].obstacle.Draw(window);
				}
				if (field.cellField[i][j].portal_1 != nullptr && gameSettings.gameMode.isPortalEnable)
				{
					field.cellField[i][j].portal_1->Draw(window);
				}
				if (field.cellField[i][j].portal_2 != nullptr && gameSettings.gameMode.isPortalEnable)
				{
					field.cellField[i][j].portal_2->Draw(window);
				}
			}
		}
		for (PlayerSnake::PartSnake n : partSnake)
		{
				window.draw(field.cellField[n.positionSnake.cellWidth][n.positionSnake.cellHeight].bodySnake.spriteBody);
		}
	}
}