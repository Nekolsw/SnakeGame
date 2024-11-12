#include "UIManager.h"

namespace SnakeGame 
{
	void UIManager::InitializationUIManager()
	{
		InitializingResources(resources);
		interfaces.uiScore.InitializingScore(resources.fontText);
		interfaces.uiTableRecord.InitializedTable(resources.fontText);
		interfaces.uiMainMenu.InitializedMainMenu(resources.fontText);
		interfaces.uiEnterName.InitializedMainMenu(resources.fontText);
		interfaces.uiPopUpEnterName.InitializedMainMenu(resources.fontText);
		interfaceState = InterfaceState::MainMenu;
	}


	void UIManager::UpdateScore()
	{

		interfaces.uiScore.UpdateScore(numberScore);
	}

	void UIManager::AddScore()
	{
		int addNumberScore = 0;

		switch (gameSettings.difficultyGame)
		{
		case SnakeGame::GameSettings::DifficultyGame::Easy:
			addNumberScore = 2;
			break;
		case SnakeGame::GameSettings::DifficultyGame::Normal:
			addNumberScore = 4;
			break;
		case SnakeGame::GameSettings::DifficultyGame::Hard:
			addNumberScore = 6;
			break;
		case SnakeGame::GameSettings::DifficultyGame::VeryHard:
			addNumberScore = 8;
			break;
		case SnakeGame::GameSettings::DifficultyGame::Hell:
			addNumberScore = 10;
			break;
		default:
			break;
		}

		numberScore += addNumberScore;
		UpdateScore();
	}
	void UIManager::ResetScore()
	{
		numberScore = 0;
	}

	void UIManager::AddPlayerInTable(std::string namePlayerTable, int numberScore)
	{
		interfaces.uiTableRecord.UpdateNumberScorePlayer(namePlayerTable, numberScore);
	}

	void UIManager::ManagementMainMenu(sf::Event& event, sf::Window& window)
	{

		gameState = GameState::Pause; 
		bool isMenuClosed = interfaces.uiMainMenu.ChoiceItemMenu(event, window, gameSettings, resources);
		if (isMenuClosed) 
		{
			gameState = GameState::Playing;
			interfaceState = InterfaceState::Game;
		}
		
	}

	void UIManager::PopUpEnteredName(sf::Event& event)
	{
		if (interfaceState == InterfaceState::IsEnterName) 
		{
			bool willNameEntered = interfaces.uiPopUpEnterName.PopUpWillNameEntered(event);

			if (willNameEntered && interfaces.uiPopUpEnterName.answerIsSelected)
			{
				interfaceState = InterfaceState::EnterName;
				
			}
			else if (!willNameEntered && interfaces.uiPopUpEnterName.answerIsSelected)
			{
				ResetScore();
				UpdateScore();
				interfaceState = InterfaceState::MainMenu;
			}
		}
	}

	void UIManager::PopUpTableRecord(sf::Event& event)
	{
		bool isSelectedMainMenu = interfaces.uiTableRecord.SelectedEventButton(event);

		if (interfaceState == InterfaceState::PopUpTableRecord)
		{

			if (interfaces.uiTableRecord.isSelected && isSelectedMainMenu)
			{
				interfaceState = InterfaceState::MainMenu;
			}
			else if (interfaces.uiTableRecord.isSelected && !isSelectedMainMenu) 
			{
				interfaceState = InterfaceState::Game;
				gameState = GameState::Playing;
			}
		}
	}

	void UIManager::EnterNamePlayer(sf::Event& event) 
	{
		if (interfaceState == InterfaceState::EnterName)
		{
			interfaces.uiEnterName.EnterPlayerName(event, resources);

			if (interfaces.uiEnterName.isPlayerNameEnter)
			{
				interfaceState = InterfaceState::PopUpTableRecord;
				AddPlayerInTable(interfaces.uiEnterName.playerName, numberScore);
				ResetScore();
				UpdateScore();
			}
		}
	}

	void UIManager::DrawUI(sf::RenderWindow& window)
	{
		switch (interfaceState)
		{
		case SnakeGame::UIManager::InterfaceState::MainMenu:
			interfaces.uiMainMenu.DrawMainMenu(window, resources.fontText, interfaces.uiTableRecord);
			break;
		case SnakeGame::UIManager::InterfaceState::Game:
			interfaces.uiScore.DrawScore(window);
			break;
		case SnakeGame::UIManager::InterfaceState::IsEnterName:
			interfaces.uiPopUpEnterName.DrawPopUp(window);
			break;
		case SnakeGame::UIManager::InterfaceState::EnterName:
			interfaces.uiEnterName.DrawEnterText(window);
			break;
		case SnakeGame::UIManager::InterfaceState::PopUpTableRecord:
			interfaces.uiTableRecord.DrawTableGameOver(window, resources, numberPlayerNameGameOverTable);
			break;

		default:
			break;
		}
	}

	void UIManager::UpdateEvent(sf::Event& event, sf::Window& window)
	{
		switch (interfaceState)
		{
		case UIManager::InterfaceState::EnterName:
			EnterNamePlayer(event);
			break;
		case UIManager::InterfaceState::Game:
			break;
		case UIManager::InterfaceState::PopUpTableRecord:
			PopUpTableRecord(event);
			break;
		case UIManager::InterfaceState::IsEnterName:
			PopUpEnteredName(event);
			break;
		case UIManager::InterfaceState::MainMenu:
			ManagementMainMenu(event, window);
		}
	}

}