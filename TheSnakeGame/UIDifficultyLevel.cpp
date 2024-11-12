#include "UIDifficultyLevel.h"
namespace SnakeGame
{
	void UIDifficultyLevel::InitializedSettings(sf::Font& font)
	{

		SetTextScreen(textHeader, "Difficulty level", 48, sf::Color::Cyan, font, { 650.f, 190.f }, { 0.5f, 0.5f });
		SetTextScreen(textDifficulty, "Difficulty: ", 32, sf::Color::Cyan, font, { 500.f, 230.f }, { 0.f, 0.f });
		SetTextScreen(textNumberDifficulty, "1", 32, sf::Color::Green, font, { 700.f, 230.f }, { 0.f, 0.f });
		SetRectangleShape(settingsBackground, { 400.f, 200.f }, sf::Color(25, 25, 25, 235), { 0.5f, 0.5f }, { 443.f, 160.f }, sf::Color::Cyan, 1.f);
	}

	void UIDifficultyLevel::Playback(sf::SoundBuffer& buffer, GameSettings& gameSettings)
	{
		if (gameSettings.isPlaySound)
		{
			soundGame.setBuffer(buffer);
			soundGame.play();
		}
	}

	bool UIDifficultyLevel::ChoiceDifficulty(sf::Event& event, GameSettings& gameSettings, GameResources& gameResouces)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				Playback(gameResouces.menuHover, gameSettings);
				if (numberDifficulty > 1) 
				{
					numberDifficulty -= 1;
					gameSettings.difficultyGame = static_cast<GameSettings::DifficultyGame>(numberDifficulty);
				}
				break;

			case sf::Keyboard::D:
				Playback(gameResouces.menuHover, gameSettings);
				if (numberDifficulty < 5)
				{
					numberDifficulty += 1;
					gameSettings.difficultyGame = static_cast<GameSettings::DifficultyGame>(numberDifficulty);
				}
				break;
			case sf::Keyboard::Escape:
				return true;
			default:
				break;
			}
		}
		UpdateTextScreen(textNumberDifficulty, std::to_string(numberDifficulty));
		return false;
	}


	void UIDifficultyLevel::DrawSettings(sf::RenderWindow& window)
	{
		window.draw(settingsBackground);
		window.draw(textHeader);
		window.draw(textDifficulty);
		window.draw(textNumberDifficulty);

	}
}