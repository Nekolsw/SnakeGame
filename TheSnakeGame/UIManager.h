#pragma once
#include "UIScore.h"
#include "UIMainMenu.h"
#include "UIEnterName.h"
#include "UIPopUpEnterName.h"
#include "Resources.h"
#include "GameSettings.h"

namespace SnakeGame 
{
	class UIManager
	{
		struct Interface 
		{
			UIScore uiScore;
			UITableRecord uiTableRecord;
			UIMainMenu uiMainMenu;
			UIEnterName uiEnterName;
			UIPopUpEnterName uiPopUpEnterName;
		};

		int numberScore = 0, numberPlayerNameGameOverTable = 5;
		GameResources resources;
		Interface interfaces;
	public:
		GameSettings gameSettings;
		enum class InterfaceState
		{
			MainMenu = 0,
			Game,
			EnterName,
			IsEnterName,
			PopUpTableRecord,
			MenuItem
		};
		InterfaceState interfaceState;

		enum GameState
		{
			Playing = 0,
			Pause
		};

		GameState gameState;

		void InitializationUIManager();
		void UpdateScore();
		void AddScore();
		void ResetScore();
		void DrawUI(sf::RenderWindow& window);
		void UpdateEvent(sf::Event& event, sf::Window& window);
		void AddPlayerInTable(std::string namePlayerTable, int numberScore);
		void ManagementMainMenu(sf::Event& event, sf::Window& window);
		void PopUpEnteredName(sf::Event& event);
		void PopUpTableRecord(sf::Event& event);
		void EnterNamePlayer(sf::Event& event);

	};

}
