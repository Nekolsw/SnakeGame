#pragma once
#include <list>
#include "GameObject.h"
#include "Constants.h"
#include "GameMath.h"
namespace SnakeGame
{
	class PlayerSnake
	{
	private:

		struct TexturePartSnake
		{
			sf::Texture headTexture, bodyTexture, tailTexture, turnTexture;
		};

		struct SizePartSnake
		{
			int sizeWidth = SNAKE_SIZE, sizeHeight = SNAKE_SIZE;
		};

		float timeSinceGameFinish = 0;
		
		bool isDirectionSelect = false;
	public:

		enum class SnakeDirection
		{
			Right = 0,
			Left,
			Up,
			Down
		};

		struct PartSnake 
		{
			sf::Texture bodyTexture;
			sf::Sprite spriteBody;
			PositionField positionSnake = { (int)CELL_FOR_WIDHT / 2, (int)CELL_FOR_HEIGHT / 2 };
			SnakeDirection snakePartDirection = SnakeDirection::Left;
			SizePartSnake sizePartSnake;
		};

		TexturePartSnake texturePartSnake;

		void InitializedSnake(std::list <PartSnake>& partsSnake, sf::Texture& gameHeadTexture, sf::Texture& gameBodyTexture, sf::Texture& gameTailTexture, sf::Texture& gameTurnTexture);

		void UpdateSnakeDirection(std::list <PartSnake>& headSnake, float& deltaTime, float snakeSpeed);

		void AddPartSnake(std::list <PartSnake>& partsSnake);

	private:

		void InitializedPartSnake(PartSnake& partSnake, sf::Texture& gameTexture, PositionField positionPart);

		void UpdatePositionPart(std::list <PartSnake>& partsSnake, PositionField newPosition, SizePartSnake newSizePartSnake);

	};
}

