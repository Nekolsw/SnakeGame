#pragma once
#include "UIConstructor.h"
namespace SnakeGame
{
	class UIScore
	{
		sf::Text scoreUI;
	public:
		void InitializingScore(sf::Font& font);
		void UpdateScore(int& numberScore);
		void DrawScore(sf::RenderWindow& window);
	};
}
