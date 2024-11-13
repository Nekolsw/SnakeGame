#include "UIGameModes.h"
namespace SnakeGame
{
	void UIGameModes::InitializedMainMenu(sf::Font& font)
	{
		SetTextScreen(textHeader, "Game mode", 48, sf::Color::Cyan, font, { 650.f, 190.f }, { 0.5f, 0.5f });
		SetTextScreen(text, "Adding moving obstacles", 24, sf::Color::Green, font, { 495.f, 265.f }, { 0.f, 0.f });
		SetRectangleShape(checkMoveObstacle, { 20.f, 20.f }, sf::Color(25, 25, 25, 255), { 0.5f, 0.5f }, { 465.f, 270.f }, sf::Color::Cyan, 2.f);
		listTextGameModeItems.push_back(text);
	
		beginGameModeItem = GameModeItems::isMoveObstacle;
		textGameModeIter = listTextGameModeItems.begin();
		SetRectangleShape(gameModeBackground, { 400.f, 500.f }, sf::Color(25, 25, 25, 235), { 0.5f, 0.5f }, { 443.f, 160.f }, sf::Color::Cyan, 1.f);
	}
	void UIGameModes::Playback(sf::SoundBuffer& buffer, GameSettings& gameSettings)
	{
		if (gameSettings.isPlaySound)
		{
			soundGame.setBuffer(buffer);
			soundGame.play();
		}
	}
	bool UIGameModes::ChoiceGameMode(sf::Event& event, GameSettings& gameSettings, GameResources& gameResouces)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				if (beginGameModeItem > GameModeItems::isMoveObstacle)
				{
					Playback(gameResouces.menuHover, gameSettings);
					--accountGameModeItems;
					beginGameModeItem = static_cast<GameModeItems>(accountGameModeItems);
					textGameModeIter->setFillColor(sf::Color::Cyan);
					--textGameModeIter;
					textGameModeIter->setFillColor(sf::Color::Green);
				}
				break;

			case sf::Keyboard::S:
				if (beginGameModeItem < GameModeItems::isMoveObstacle)
				{
					Playback(gameResouces.menuHover, gameSettings);
					++accountGameModeItems;
					beginGameModeItem = static_cast<GameModeItems>(accountGameModeItems);
					textGameModeIter->setFillColor(sf::Color::Cyan);
					++textGameModeIter;
					textGameModeIter->setFillColor(sf::Color::Green);
				}
				break;
			case sf::Keyboard::Enter:
				Playback(gameResouces.menuEnter, gameSettings);
				switch (beginGameModeItem)
				{
				case SnakeGame::UIGameModes::isMoveObstacle:
					gameSettings.gameMode.isMoveObstacle = !gameSettings.gameMode.isMoveObstacle;
					break; 
				default:
					break;
				}
				SetRectangleShape(checkMoveObstacle, { 20.f, 20.f }, (bool)gameSettings.gameMode.isMoveObstacle ? sf::Color::Cyan : sf::Color(25, 25, 25, 255), { 0.5f, 0.5f }, { 465.f, 270.f },
					(bool)gameSettings.gameMode.isMoveObstacle ? sf::Color(25, 25, 25, 255) : sf::Color::Cyan, 2.f);

			case sf::Keyboard::Escape:
				return true;
			default:
				break;
			}
		}
		return false;
	}

	void UIGameModes::DrawGameMode(sf::RenderWindow& window)
	{
			window.draw(gameModeBackground);
			window.draw(textHeader);
			window.draw(checkMoveObstacle);
			for (std::list <sf::Text>::iterator drawTextMenuIter = listTextGameModeItems.begin(); drawTextMenuIter != listTextGameModeItems.end(); ++drawTextMenuIter)
			{
				window.draw(*drawTextMenuIter);
			}
	}
}