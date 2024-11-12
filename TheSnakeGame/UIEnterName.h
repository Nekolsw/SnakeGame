#pragma once
#include "UIConstructor.h"
#include "Resources.h"
namespace SnakeGame 
{
	class UIEnterName
	{
		sf::Text enterNameText;
		sf::RectangleShape enterNameBackground;
	public:
		sf::String playerName = "XYZ";
		bool isPlayerNameEnter = false;
		void EnterPlayerName(sf::Event& event, GameResources& resources);
		void DrawEnterText(sf::RenderWindow& window);
		void InitializedMainMenu(sf::Font& font);
	};
}

