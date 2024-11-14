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
		assert(resources.obstacleTexture.loadFromFile(RESOURCES_PATH + "Obstacle.png"));
		assert(resources.portalTexture.loadFromFile(RESOURCES_PATH + "Portal.png"));
		

		//Load font
		assert(resources.fontText.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Bold.ttf"));

		//Load sound
		assert(resources.snakeHit.loadFromFile(RESOURCES_PATH + "ClapApple.wav"));
		assert(resources.playerDeath.loadFromFile(RESOURCES_PATH + "GameOverSound.wav"));
		assert(resources.menuHover.loadFromFile(RESOURCES_PATH + "Theevilsocks__menu-hover.wav"));
		assert(resources.menuEnter.loadFromFile(RESOURCES_PATH + "Timgormly__Enter.wav"));
	}




}