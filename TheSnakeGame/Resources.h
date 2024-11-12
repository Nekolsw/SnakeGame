#pragma once
#include <cassert>
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace SnakeGame
{
	struct GameResources {
		sf::Texture headTexture, bodyTexture, tailSnakeTexture, turnBodySnakeTexture, classicCellFiledTexture, redAppleTexture, obstacleTexture;
		sf::SoundBuffer appleEat, playerDeath, menuHover, menuEnter, snakeHit;
		sf::Font fontText;
	};

	void InitializingResources(GameResources& resources);


}