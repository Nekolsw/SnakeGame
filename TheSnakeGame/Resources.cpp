#include "Resources.h"

namespace SnakeGame
{
	void InitializingResources(GameResources& resources)
	{
		//Load image
		assert(resources.headTexture.loadFromFile(RESOURCES_PATH + "SnakeHead.png"));
		assert(resources.bodyTexture.loadFromFile(RESOURCES_PATH + "SnakeBody.png"));
		assert(resources.tailSnakeTexture.loadFromFile(RESOURCES_PATH + "SnakeTail.png"));
		assert(resources.turnBodySnakeTexture.loadFromFile(RESOURCES_PATH + "SnakeBodyTurn.png"));
		assert(resources.classicCellFiledTexture.loadFromFile(RESOURCES_PATH + "ClassicCellFiled.png"));
		assert(resources.redAppleTexture.loadFromFile(RESOURCES_PATH + "GreenApple.png"));

		//Load font
		assert(resources.fontText.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Bold.ttf"));

		//Load sound
		//assert(resources.appleEat.loadFromFile(RESOURCES_PATH + "AppleEat.wav"));
		//assert(resources.playerDeath.loadFromFile(RESOURCES_PATH + "Death.wav"));
	}




}