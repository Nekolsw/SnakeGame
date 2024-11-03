#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameMath.h"
#include "Constants.h"
#include "Apple.h"
#include "PlayerSnake.h"

namespace SnakeGame
{
	class PlayingField
	{
		sf::Texture cellTexture;

		enum class ItemType 
		{
			Apple = 0,
			Obstacle,
			PartSnake,
			Null
		};

		struct CellField 
		{
			Position2D cellPosition;
			Apple* apple = nullptr;
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
			CellField cellField[CELL_FOR_WIDHT][CELL_FOR_HEIGHT];
		};

		TypeField typeField = TypeField::Classic;
		void SetTextureSprite(sf::Texture gameTextureCell, Field& field);
		void InitializingField(sf::Texture gameTextureCell, Field& field);
		void AddAppleForField(Apple& apple, Field& field);
		void DeleteAppleForField(PositionField positionField, Field& field);
		void UpdateSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		void DeleteSnakeBodyForField(std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		void Draw(sf::RenderWindow& window, std::list<PlayerSnake::PartSnake>& partSnake, Field& field);
		

	};
}