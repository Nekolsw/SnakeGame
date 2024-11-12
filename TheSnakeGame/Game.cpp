#include "Game.h"

namespace SnakeGame
{
	void Game::AppleInitialization(GameStruct& gameStruct)
	{
		gameStruct.redApple.Initialization(APPLE_SIZE, gameStruct.resources.redAppleTexture);
		gameStruct.playingFiled.AddAppleForField(gameStruct.redApple, gameStruct.field);
	}


	void Game::Playback(sf::SoundBuffer& buffer)
	{
		if (GetUIManager().gameSettings.isPlaySound) 
		{
			gameStruct.soundGame.setBuffer(buffer);
			gameStruct.soundGame.play();
		}
	}

	UIManager& Game::GetUIManager()
	{
		static UIManager uiManager = UIManager();
		return uiManager;
	}

	void Game::RunApplication(GameStruct& gameStruct)
	{
		gameStruct.backgroundMusic.openFromFile(RESOURCES_PATH + "Clinthammer__Background_Music.wav");
		gameStruct.backgroundMusic.setLoop(true);
		gameStruct.backgroundMusic.play();
		GetUIManager().InitializationUIManager();
		gameStruct.timeSinceGameStart = 0;
		InitializingResources(gameStruct.resources);
		gameStruct.snakeClass.InitializedSnake(gameStruct.playerSnake, gameStruct.resources.headTexture, gameStruct.resources.bodyTexture, gameStruct.resources.tailSnakeTexture, gameStruct.resources.turnBodySnakeTexture);
		gameStruct.playingFiled.InitializingField(gameStruct.resources.classicCellFiledTexture, gameStruct.field);
		gameStruct.obstacle.Initialization(OBSTACLE_SIZE, gameStruct.resources.obstacleTexture);
		gameStruct.playingFiled.AddObstacleForField(gameStruct.obstacle, gameStruct.field);
		AppleInitialization(gameStruct);
		gameStruct.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		gameStruct.background.setFillColor(sf::Color(31, 31, 31));
		gameStruct.background.setPosition(0.f, 0.f);

	}

	void Game::RestartGame(GameStruct& gameStruct)
	{
		GetUIManager().interfaceState = UIManager::InterfaceState::IsEnterName;
		GetUIManager().gameState = GetUIManager().Pause;
		gameStruct.snakeClass.ReloadSnake(gameStruct.playerSnake);
		gameStruct.playingFiled.ReloadField(gameStruct.field);
		gameStruct.playingFiled.AddObstacleForField(gameStruct.obstacle, gameStruct.field);
		gameStruct.playingFiled.AddAppleForField(gameStruct.redApple, gameStruct.field);
		gameStruct.timeSinceGameStart = 0;
	}

	void Game::UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window)
	{
		if (GetUIManager().gameState == GetUIManager().Playing)
		{
			if (gameStruct.timeSinceGameStart <= PAUSE_LENGHT_START)
			{
				gameStruct.timeSinceGameStart += deltaTime;
			}
			else
			{
				gameStruct.playingFiled.DeleteSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
				gameStruct.snakeClass.UpdateSnakeDirection(gameStruct.playerSnake, deltaTime, PAUSE_LENGHT_MOVEMENT / int(GetUIManager().gameSettings.difficultyGame));
				switch (gameStruct.field.cellField[gameStruct.playerSnake.front().positionSnake.cellWidth][gameStruct.playerSnake.front().positionSnake.cellHeight].itemType)
				{
				case PlayingField::ItemType::Apple:
					gameStruct.playingFiled.UpdateSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
					Playback(gameStruct.resources.snakeHit);
					gameStruct.snakeClass.AddPartSnake(gameStruct.playerSnake);
					gameStruct.playingFiled.AddAppleForField(gameStruct.redApple, gameStruct.field);
					gameStruct.playingFiled.DeleteAppleForField(gameStruct.playerSnake.front().positionSnake, gameStruct.field);
					GetUIManager().AddScore();
					break;
				case PlayingField::ItemType::Obstacle:
					gameStruct.playingFiled.UpdateSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
					Playback(gameStruct.resources.snakeHit);
					RestartGame(gameStruct);
					break;
				default:
					gameStruct.playingFiled.UpdateSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
					break;
				}

				if (gameStruct.field.cellField[gameStruct.playerSnake.front().positionSnake.cellWidth][gameStruct.playerSnake.front().positionSnake.cellHeight].itemType == PlayingField::ItemType::PartSnake) 
				{
					RestartGame(gameStruct);
				}
			}

			gameStruct.playingFiled.UpdateSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
		}

		if (GetUIManager().gameSettings.isPlayMusic && gameStruct.backgroundMusic.getStatus() != sf::SoundStream::Status::Playing)
		{
			gameStruct.backgroundMusic.play();
		}
		else if (!GetUIManager().gameSettings.isPlayMusic)
		{
			gameStruct.backgroundMusic.stop();
		}
	}

	void Game::UpdateEvent(sf::Event& event, sf::Window& window)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				Playback(gameStruct.resources.menuEnter);
				if (GetUIManager().gameState == UIManager::GameState::Playing) 
				{
					RestartGame(gameStruct);
				}
				break;

			case sf::Keyboard::P:
				Playback(gameStruct.resources.menuEnter);
				if(GetUIManager().gameState == GetUIManager().Pause && GetUIManager().interfaceState == UIManager::InterfaceState::Game)
				{
					GetUIManager().gameState = GetUIManager().Playing;
					gameStruct.timeSinceGameStart = 0;
				}
				else 
				{
					GetUIManager().gameState = GetUIManager().Pause;
				}
				break;
			default:
				break;
			}
		}
		GetUIManager().UpdateEvent(event, window);
		
		
	}

	void Game::DrawGame(GameStruct& gameStruct, sf::RenderWindow& window)
	{
		window.draw(gameStruct.background);
		gameStruct.playingFiled.Draw(window, gameStruct.playerSnake, gameStruct.field);
		GetUIManager().DrawUI(window);
	}

}