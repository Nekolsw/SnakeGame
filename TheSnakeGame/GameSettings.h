#pragma once
namespace SnakeGame
{
	struct GameSettings
	{
		bool isPlayMusic = true, isPlaySound = true;
		enum class DifficultyGame
		{
			Easy = 1,
			Normal,
			Hard,
			VeryHard,
			Hell
		};

		DifficultyGame difficultyGame = DifficultyGame::Easy;
	};
}