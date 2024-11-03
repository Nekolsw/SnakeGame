#pragma once
#include <cassert>
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace SnakeGame
{
	struct GameResources {
		sf::Texture headTexture, bodyTexture, tailSnakeTexture, turnBodySnakeTexture, classicCellFiledTexture, redAppleTexture;
		sf::SoundBuffer appleEat, playerDeath;
		sf::Font fontText;
	};

	void InitializingResources(GameResources& resources);


}