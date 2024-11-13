#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameMath.h"
#include "Constants.h"
#include "Apple.h"
#include "Obstacle.h"
#include "PlayerSnake.h"
#include "GameSettings.h"

namespace SnakeGame
{
	class PlayingField
	{
	public:
		enum class ItemType
		{
			Apple = 1,
			Obstacle,
			ObstacleBorder,
			HeadSnake,
			PartSnake,
			Null
		};
	private:
		sf::Texture cellTexture;

		struct CellField 
		{
			Position2D cellPosition;
			Apple* apple = nullptr;
			Obstacle obstacle;
			PlayerSnake::PartSnake bodySnake;
			sf::Sprite spriteCell;
			ItemType itemType;
		};

		enum TypeField 
		{
			Classic = 0,
			Hard
		};


	public: 


		struct Field
		{
			CellField cellField[CELL_FOR_WIDTH][CELL_FOR_HEIGHT];
		};

		TypeField typeField = TypeField::Classic;
		void SetTextureSprite(sf::Texture gameTextureCell, Field& field);
		void InitializingField(sf::Texture gameTextureCell, Field& field);
		void ReloadField(Field& field);
		void AddAppleForField(Apple& apple, Field& field);
		void AddRandomObstacleForField(Obstacle& obstacle, Field& field, GameSettings& gameSettings);
		void AddBorderObstacleForField(Obstacle& obstacle, Field& field);
		void DeleteObstacleForField(Field& field);
		void DeleteAppleForField(PositionField positionField, Field& field);
		void UpdateSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		void DeleteSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		void Draw(sf::RenderWindow& window, std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		

	};
}