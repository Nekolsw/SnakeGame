#include "Game.h"

namespace SnakeGame
{
	void Game::AppleInitialization(GameStruct& gameStruct)
	{
		gameStruct.redApple.Initialization(APPLE_SIZE, gameStruct.resources.redAppleTexture);
		gameStruct.playingFiled.AddAppleForField(gameStruct.redApple, gameStruct.field);
	}

	void Game::EnterPlayerName(sf::Event event, sf::RenderWindow& window)
	{
		if (sf::Keyboard::isKeyPressed && event.key.code == sf::Keyboard::Enter) 
		{
			gameStruct.isPlayerNameEnter = true;
		}

		if (sf::Keyboard::isKeyPressed && event.key.code == sf::Keyboard::BackSpace)
		{
			gameStruct.playerName = gameStruct.playerName.substring(0, gameStruct.playerName.getSize() - 1);
		}

		if (event.type == sf::Event::TextEntered && !gameStruct.isPlayerNameEnter)
		{
			gameStruct.playerName += static_cast<char>(event.text.unicode);
		}
		SetTextScreen(gameStruct.enterNameText, "Player's name: " + gameStruct.playerName, 56, sf::Color::Cyan, gameStruct.resources.fontText, {350.f - gameStruct.playerName.getSize()*8, 300.f}, {0.0f, 0.0f});
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
		gameStruct.playingFiled.InitializingField(gameStruct.resources.classicCellFiledTexture, gameStruct.field);
		gameStruct.snakeClass.InitializedSnake(gameStruct.playerSnake, gameStruct.resources.headTexture, gameStruct.resources.bodyTexture, gameStruct.resources.tailSnakeTexture, gameStruct.resources.turnBodySnakeTexture);
		AppleInitialization(gameStruct);
		gameStruct.background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		gameStruct.background.setFillColor(sf::Color(31, 31, 31));
		gameStruct.background.setPosition(0.f, 0.f);

	}

	void Game::UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window, sf::Event& event)
	{
		if (gameStruct.timeSinceGameStart <= PAUSE_LENGHT_START)
		{
			gameStruct.timeSinceGameStart += deltaTime;
		}
		else
		{
			gameStruct.playingFiled.DeleteSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
			gameStruct.snakeClass.UpdateSnakeDirection(gameStruct.playerSnake, deltaTime, PAUSE_LENGHT_MOVEMENT / gameStruct.gameSettings.snakeSpeed);
		}
		gameStruct.playingFiled.UpdateSnakeBodyForField(gameStruct.playerSnake, gameStruct.field);
		if (gameStruct.field.cellField[gameStruct.playerSnake.front().positionSnake.cellWidth][gameStruct.playerSnake.front().positionSnake.cellHeight].apple != nullptr)
		{
			gameStruct.playingFiled.DeleteAppleForField(gameStruct.playerSnake.front().positionSnake, gameStruct.field);
			gameStruct.playingFiled.AddAppleForField(gameStruct.redApple, gameStruct.field);
			gameStruct.snakeClass.AddPartSnake(gameStruct.playerSnake);
		}
	}

	void Game::DrawGame(GameStruct& gameStruct, sf::RenderWindow& window)
	{
		window.draw(gameStruct.background);
		GetUIManager().DrawUI(window);
		gameStruct.playingFiled.Draw(window, gameStruct.playerSnake, gameStruct.field);
		if (!gameStruct.isPlayerNameEnter)
		{
			window.draw(gameStruct.enterNameText);
		}
	}
}