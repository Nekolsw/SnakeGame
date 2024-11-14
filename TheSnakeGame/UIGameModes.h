#pragma once
#include <list>
#include <iterator>
#include "UIConstructor.h"
#include "GameSettings.h"
namespace SnakeGame
{
	class UIGameModes
	{
		sf::Sound soundGame;
		sf::Text textHeader, text;
		sf::RectangleShape gameModeBackground, checkMoveObstacle, checkPortal;
	public:
		enum GameModeItems
		{
			isMoveObstacle = 0,
			isPortalEnable
		};
		void InitializedMainMenu(sf::Font& font);
		void Playback(sf::SoundBuffer& buffer, GameSettings& gameSettings);
		bool ChoiceMenu(sf::Event& event, GameSettings& gameSettings, GameResources& gameResouces);
		void Draw(sf::RenderWindow& window);
	private:
		int accountGameModeItems = 0;
		GameModeItems beginGameModeItem;
		std::list <sf::Text> listTextGameModeItems;
		std::list <sf::Text>::iterator textGameModeIter;
	};

}