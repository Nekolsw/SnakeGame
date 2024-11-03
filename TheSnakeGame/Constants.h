#pragma once
#include <string>

namespace SnakeGame 
{
	const std::string RESOURCES_PATH = "Resources/\\";
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const int APPLE_SIZE = 50;
	const int SNAKE_SIZE = 80;
	const int TEXT_SCORE_SIZE = 46;
	const int FIELD_OFFSET_WIDTH = 40;
	const int FIELD_OFFSET_HEIGHT = 120;
	const float PAUSE_LENGHT_MOVEMENT = 1.f;
	const float PAUSE_LENGHT_START = 2.f;
	const int MAX_EFFECT_APPLE = 3;
	const int GAME_FIELD_WIDTH = 1200;
	const int GAME_FIELD_HEIGHT = 640;

	//Calculating the number of cells in the field
	const int SIZE_CELL = 80;
	const int CELL_FOR_WIDHT = GAME_FIELD_WIDTH / SIZE_CELL;
	const int CELL_FOR_HEIGHT = GAME_FIELD_HEIGHT / SIZE_CELL;
}