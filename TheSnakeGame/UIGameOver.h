#pragma once
#include <SFML/Graphics.hpp>
namespace SnakeGame
{
	class UIGameOver
	{
		sf::Text scoreUI;
	public:
		void InitializingScore(sf::Font& font);
		void UpdateScore(int& numberScore);
		void DrawScore(sf::RenderWindow& window);
	};
}
