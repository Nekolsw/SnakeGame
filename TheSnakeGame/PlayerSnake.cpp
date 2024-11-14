#include "PlayerSnake.h"

namespace SnakeGame {

	void PlayerSnake::InitializedPartSnake(PartSnake& partSnake, sf::Texture& gameTexture, PositionField positionPart)
	{
		partSnake.positionSnake = positionPart;
		partSnake.snakePartDirection = SnakeDirection::Left;
		partSnake.spriteBody.setTexture(gameTexture);
		partSnake.bodyTexture = gameTexture;
		partSnake.spriteBody.setPosition(ConversionPositionCellsInScreenPosition(positionPart));
		SetSpriteRelativeOrigin(partSnake.spriteBody, 0.5f, 0.5f);
		SetSpriteSize(partSnake.spriteBody, SNAKE_SIZE, SNAKE_SIZE);
		partSnake.sizePartSnake = { SNAKE_SIZE, SNAKE_SIZE };
	}

	void PlayerSnake::InitializedSnake(std::list <PartSnake>& partsSnake, sf::Texture& gameHeadTexture, sf::Texture& gameBodyTexture, sf::Texture& gameTailTexture, sf::Texture& gameTurnTexture)
	{

		PartSnake partSnakeHead, partSnakeBody, partSnakeTail;

		texturePartSnake.headTexture = gameHeadTexture;
		texturePartSnake.bodyTexture = gameBodyTexture;
		texturePartSnake.tailTexture = gameTailTexture;
		texturePartSnake.turnTexture = gameTurnTexture;

		//Setting the initial values for the snake, the snake spawn in the center of the screen.
		InitializedPartSnake(partSnakeHead, texturePartSnake.headTexture, { (int)CELL_FOR_WIDTH / 2, (int)CELL_FOR_HEIGHT / 2 });

		InitializedPartSnake(partSnakeBody, texturePartSnake.bodyTexture, { (int)CELL_FOR_WIDTH / 2 + 1, (int)CELL_FOR_HEIGHT / 2 });

		InitializedPartSnake(partSnakeTail, texturePartSnake.tailTexture, { (int)CELL_FOR_WIDTH / 2 + 2, (int)CELL_FOR_HEIGHT / 2 });

		//Adding snake parts to the list that contains the entire body
		partsSnake.push_back(partSnakeHead);
		partsSnake.push_back(partSnakeBody);
		partsSnake.push_back(partSnakeTail);
	}

	void PlayerSnake::ReloadSnake(std::list <PartSnake>& partsSnake)
	{
		partsSnake.clear();
		PartSnake partSnakeHead, partSnakeBody, partSnakeTail;

		//Setting the initial values for the snake, the snake spawn in the center of the screen.
		InitializedPartSnake(partSnakeHead, texturePartSnake.headTexture, { (int)CELL_FOR_WIDTH / 2, (int)CELL_FOR_HEIGHT / 2 });

		InitializedPartSnake(partSnakeBody, texturePartSnake.bodyTexture, { (int)CELL_FOR_WIDTH / 2 + 1, (int)CELL_FOR_HEIGHT / 2 });

		InitializedPartSnake(partSnakeTail, texturePartSnake.tailTexture, { (int)CELL_FOR_WIDTH / 2 + 2, (int)CELL_FOR_HEIGHT / 2 });

		//Adding snake parts to the list that contains the entire body
		partsSnake.push_back(partSnakeHead);
		partsSnake.push_back(partSnakeBody);
		partsSnake.push_back(partSnakeTail);
	}

	void PlayerSnake::UpdatePositionPart(std::list<PartSnake>& partsSnake, PositionField newPosition, SizePartSnake newSizePartSnake)
	{
		std::list <PartSnake> ::iterator iter;
		PartSnake temp, old;

		old.positionSnake = partsSnake.front().positionSnake;
		old.snakePartDirection = partsSnake.front().snakePartDirection;
		old.spriteBody.setRotation(partsSnake.front().spriteBody.getRotation());
		old.sizePartSnake = newSizePartSnake;

		SetSpriteSize(partsSnake.front().spriteBody, newSizePartSnake.sizeWidth, newSizePartSnake.sizeHeight);
		partsSnake.front().positionSnake = newPosition;
		partsSnake.front().sizePartSnake = newSizePartSnake;

		//Cycle moving a part of the snake to its former place in ahead the standing part
		for (iter = ++partsSnake.begin(); iter != partsSnake.end(); iter++)
		{
			

			SetSpriteSize(iter->spriteBody, old.sizePartSnake.sizeWidth, old.sizePartSnake.sizeHeight);
			temp.positionSnake = iter->positionSnake;
			temp.snakePartDirection = iter->snakePartDirection;
			temp.spriteBody.setRotation(iter->spriteBody.getRotation());
			temp.sizePartSnake = iter->sizePartSnake;

			iter->positionSnake = old.positionSnake;
			iter->snakePartDirection = old.snakePartDirection;
			iter->spriteBody.setRotation(old.spriteBody.getRotation());
			iter->sizePartSnake = old.sizePartSnake;
			if (iter != --partsSnake.end()) 
			{
				iter->bodyTexture = texturePartSnake.bodyTexture;
				iter->spriteBody.setTexture(iter->bodyTexture);
			}
			else 
			{
				iter->bodyTexture = texturePartSnake.tailTexture;
				iter->spriteBody.setTexture(iter->bodyTexture);
			}

			old.positionSnake = temp.positionSnake;
			old.snakePartDirection = temp.snakePartDirection;
			old.spriteBody.setRotation(temp.spriteBody.getRotation());
			old.sizePartSnake = temp.sizePartSnake;

			//Switching the texture of a snake's body part on the turns 
			switch (iter->snakePartDirection)
			{
			case SnakeDirection::Up:
			{
				if (old.snakePartDirection == SnakeDirection::Right && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
					SetSpriteSize(iter->spriteBody, SNAKE_SIZE, -SNAKE_SIZE);
				}
				else if (old.snakePartDirection == SnakeDirection::Left && iter != --partsSnake.end())
				{
					
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);

				}
				break;
			}
			case SnakeDirection::Right:
			{
				if (old.snakePartDirection == SnakeDirection::Up && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
				}
				else if (old.snakePartDirection == SnakeDirection::Down && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
					SetSpriteSize(iter->spriteBody, -SNAKE_SIZE, SNAKE_SIZE);
				}
				break;
			}
			case SnakeDirection::Down:
			{
				if (old.snakePartDirection == SnakeDirection::Left && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
					SetSpriteSize(iter->spriteBody, SNAKE_SIZE, -SNAKE_SIZE);
				}
				else if (old.snakePartDirection == SnakeDirection::Right && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
				}
				break;
			}
			case SnakeDirection::Left:
			{
				if (old.snakePartDirection == SnakeDirection::Up && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
					SetSpriteSize(iter->spriteBody, SNAKE_SIZE, -SNAKE_SIZE);
				}
				else if (old.snakePartDirection == SnakeDirection::Down && iter != --partsSnake.end())
				{
					iter->spriteBody.setTexture(texturePartSnake.turnTexture);
				}
				break;
			}
			}
		}
	}

	void PlayerSnake::AddPartSnake(std::list<PartSnake>& partsSnake)
	{
		PartSnake partSnakeBody;
		InitializedPartSnake(partSnakeBody, texturePartSnake.tailTexture, partsSnake.back().positionSnake);
		partSnakeBody.spriteBody.setRotation(partsSnake.back().spriteBody.getRotation());
		SetSpriteSize(partSnakeBody.spriteBody, partsSnake.back().sizePartSnake.sizeWidth, partsSnake.back().sizePartSnake.sizeHeight);
		partsSnake.push_back(partSnakeBody);
	}

	void PlayerSnake::UpdateSnakeDirection(std::list <PartSnake>& headSnake, float &deltaTime, float snakeSpeed, int& numberMoveSnake, GameSettings& gameSettings)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && headSnake.front().snakePartDirection != SnakeDirection::Left && !isDirectionSelect)
		{
			headSnake.front().snakePartDirection = SnakeDirection::Right;
			isDirectionSelect = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && headSnake.front().snakePartDirection != SnakeDirection::Right && !isDirectionSelect)
		{
			headSnake.front().snakePartDirection = SnakeDirection::Left;
			isDirectionSelect = true;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && headSnake.front().snakePartDirection != SnakeDirection::Down && !isDirectionSelect)
		{
			headSnake.front().snakePartDirection = SnakeDirection::Up;
			isDirectionSelect = true;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && headSnake.front().snakePartDirection != SnakeDirection::Up && !isDirectionSelect)
		{
			headSnake.front().snakePartDirection = SnakeDirection::Down;
			isDirectionSelect = true;
		}


		// Switching directions from the player's state and moving the snake
		if (timeSinceGameFinish <= snakeSpeed)
		{
			timeSinceGameFinish += deltaTime;
		}
		else
		{
			if (gameSettings.gameMode.isMoveObstacle) 
			{
				++numberMoveSnake;
			}
			switch (headSnake.front().snakePartDirection)
			{
				case SnakeDirection::Up:
				{
					timeSinceGameFinish = 0;
					headSnake.front().spriteBody.setRotation(90.f);
					UpdatePositionPart(headSnake, { headSnake.front().positionSnake.cellWidth, headSnake.front().positionSnake.cellHeight - 1 }, { SNAKE_SIZE, SNAKE_SIZE });
					isDirectionSelect = false;
					break;
				}
				case SnakeDirection::Right:
				{
					timeSinceGameFinish = 0;
					headSnake.front().spriteBody.setRotation(0.f);
					UpdatePositionPart(headSnake, { headSnake.front().positionSnake.cellWidth + 1, headSnake.front().positionSnake.cellHeight }, { -SNAKE_SIZE, -SNAKE_SIZE });
					isDirectionSelect = false;
					break;
				}
				case SnakeDirection::Down:
				{
					timeSinceGameFinish = 0;
					headSnake.front().spriteBody.setRotation(-90.f);
					UpdatePositionPart(headSnake, { headSnake.front().positionSnake.cellWidth, headSnake.front().positionSnake.cellHeight + 1 }, { SNAKE_SIZE, SNAKE_SIZE });
					isDirectionSelect = false;
					
					break;
				}
				case SnakeDirection::Left:
				{
					timeSinceGameFinish = 0;
					headSnake.front().spriteBody.setRotation(0.f);
					UpdatePositionPart(headSnake, { headSnake.front().positionSnake.cellWidth - 1 , headSnake.front().positionSnake.cellHeight }, { SNAKE_SIZE, SNAKE_SIZE });
					isDirectionSelect = false;
					break;
				}
			}
		}
	}

}