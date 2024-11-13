#pragma once
#include "Constants.h"
namespace SnakeGame
{
	struct GameSettings
	{
		bool isPlayMusic = true, isPlaySound = true;
		int numberMovesBeforeChangingObstacles = NUMBER_MOVES_BEFORE_CHANGING_OBSTACLE;
		enum class DifficultyGame
		{
			Easy = 1,
			Normal,
			Hard,
			VeryHard,
			Hell
		};

		struct GameMode 
		{
			bool isMoveObstacle = false;
		};

		DifficultyGame difficultyGame = DifficultyGame::Easy;
		GameMode gameMode;
	};
}