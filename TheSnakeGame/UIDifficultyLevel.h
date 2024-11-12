#pragma once
#include "UIConstructor.h"
#include "UISettings.h"
#include <string>

namespace SnakeGame 
{
	class UIDifficultyLevel
	{
		sf::Text textHeader, textDifficulty, textNumberDifficulty;
		sf::RectangleShape settingsBackground, checkSound, checkMusic;
		sf::Sound soundGame;
		int numberDifficulty = 1;
	public:

		void InitializedSettings(sf::Font& font);

		void Playback(sf::SoundBuffer& buffer, GameSettings& gameSettings);

		bool ChoiceDifficulty(sf::Event& event, GameSettings& gameSettings, GameResources& gameResouces);

		void DrawSettings(sf::RenderWindow& window);

	};
}
