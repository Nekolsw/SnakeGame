#include "UIManager.h"

namespace SnakeGame 
{
	void UIManager::InitializationUIManager()
	{
		InitializingResources(resources);
		interfaces.uiScore.InitializingScore(resources.fontText);
	}
	void UIManager::AddScore()
	{
		int addNumberScore = 0;

		switch (difficultyGame)
		{
		case SnakeGame::UIManager::DifficultyGame::Easy:
			addNumberScore = 1;
			break;
		case SnakeGame::UIManager::DifficultyGame::Normal:
			addNumberScore = 2;
			break;
		case SnakeGame::UIManager::DifficultyGame::Hard:
			addNumberScore = 3;
			break;
		case SnakeGame::UIManager::DifficultyGame::VeryHard:
			addNumberScore = 4;
			break;
		case SnakeGame::UIManager::DifficultyGame::Hell:
			addNumberScore = 5;
			break;
		default:
			break;
		}

		numberScore += addNumberScore;

		interfaces.uiScore.UpdateScore(numberScore);
	}
	void UIManager::DrawUI(sf::RenderWindow& window)
	{
		interfaces.uiScore.DrawScore(window);
	}
}