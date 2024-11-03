#pragma once
#include "UIScore.h"
#include "Resources.h"

namespace SnakeGame 
{
	class UIManager
	{
		struct Interface 
		{
			UIScore uiScore;
		};

		int numberScore;
		GameResources resources;
		Interface interfaces;
	public:

		enum class MenuState
		{
			Main = 0,
			TableRecord,
			GameModes,
			Setting,
			Exit,
			GameOver
		};

		enum class DifficultyGame
		{
			Easy = 0,
			Normal,
			Hard,
			VeryHard,
			Hell
		};

		DifficultyGame difficultyGame;

		void InitializationUIManager();
		void AddScore();
		void DrawUI(sf::RenderWindow& window);
	};

}
