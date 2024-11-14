#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Resources.h"
#include "PlayingField.h"
#include "PlayerSnake.h"
#include "RedApple.h"
#include "Obstacle.h"
#include "Portal.h"
#include "UIManager.h"

namespace SnakeGame 
{
	class Game
	{

		struct GameStruct
		{
			PlayingField playingFiled; 
			sf::Sound soundGame;
			RedApple redApple;
			Portal portal_1, portal_2;
			Obstacle obstacle;
			PlayingField::Field field;
			GameResources resources;
			PlayerSnake snakeClass;
			std::list <PlayerSnake::PartSnake> playerSnake;
			sf::RectangleShape background;
			int numberMoveSnake = 0;
			float timeSinceGameStart;
			bool isPlayerNameEnter = false;
			sf::Music backgroundMusic;
		};

		enum class MyEnumClass
		{
			redApple = 0,
		};

		void AppleInitialization(GameStruct& gameStruct);
	public:
		GameStruct gameStruct;
		UIManager& GetUIManager();
		void Playback(sf::SoundBuffer& buffer);
		void RunApplication(GameStruct& gameStruct);
		void RestartGame(GameStruct& gameStruct);
		void UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window);
		void UpdateEvent(sf::Event& event, sf::Window& window);
		void DrawGame(GameStruct& gameStruct, sf::RenderWindow& window);


	};
}