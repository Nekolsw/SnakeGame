#pragma once
#include "UIConstructor.h"
#include "UISettings.h"
#include "UITableRecord.h"
#include "UIDifficultyLevel.h"
#include <list>
#include <iterator>
namespace SnakeGame
{
	class UIMainMenu
	{
		struct UIMenuItem 
		{
			UISettings uiSettings;
			UIDifficultyLevel uiDifficultyLevel;
		};
		UIMenuItem uiMenuItem; 
		sf::Sound soundGame;
		sf::Text textHeader, text;
		sf::RectangleShape menuBackground;
		int accountMenuItems = 0;
	public: 
		bool isMenuItemSelected = false;
		enum MenuItems 
		{
			StartPLaying = 0,
			DifficultyLevel, 
			TableScore, 
			GameModes,
			Settings,
			Exit,
		};
		void InitializedMainMenu(sf::Font& font);
		void Playback(sf::SoundBuffer& buffer, GameSettings& gameSettings);
		bool ChoiceItemMenu(sf::Event& event, sf::Window& window, GameSettings& gameSettings, GameResources& gameResources);
		void DrawMainMenu(sf::RenderWindow& window, sf::Font& font, UITableRecord& uiTableRecord);
	private:
		MenuItems beginMenuItem;
		std::list <sf::Text> listTextMenuItems;
		std::list <sf::Text>::iterator textMenuIter;
	};
}