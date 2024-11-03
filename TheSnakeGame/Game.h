#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Resources.h"
#include "PlayingField.h"
#include "PlayerSnake.h"
#include "RedApple.h"
#include "GameSettings.h"
#include "UIManager.h"

namespace SnakeGame 
{
	class Game
	{

		enum GameState
		{
			Dead = 0,
			Alive,
			Pause
		};

		struct GameStruct
		{
			GameSettings gameSettings;
			PlayingField playingFiled;
			RedApple redApple;
			PlayingField::Field field;
			GameResources resources;
			PlayerSnake snakeClass;
			std::list <PlayerSnake::PartSnake> playerSnake;
			sf::RectangleShape background;
			float timeSinceGameStart;
			bool isPlayerNameEnter = false;
			sf::Music backgroundMusic;
			sf::String playerName = "XYZ";
			sf::Text enterNameText;
		};

		enum class MyEnumClass
		{
			redApple = 0,
		};

		void AppleInitialization(GameStruct& gameStruct);
	public:
		GameStruct gameStruct;
		GameSettings gameSettings;
		UIManager& GetUIManager();

		void EnterPlayerName(sf::Event event, sf::RenderWindow& window);
		void RunApplication(GameStruct& gameStruct);
		void UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window, sf::Event& event);
		void DrawGame(GameStruct& gameStruct, sf::RenderWindow& window);


	};
}