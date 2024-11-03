#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "UIMath.h"
#include "Resources.h"
namespace SnakeGame
{

	void SetTextScreen(sf::Text& textScreen, std::string stringScreen, int textSize, sf::Color textColor,
		sf::Font& font, UIPosition2D gameTextPosition, UIPosition2D textRevelationOrigin, bool isTextBold = false);

	void UpdateTextScreen(sf::Text& textScreen, std::string textString);

	void UpdateTextScreen(sf::Text& textScreen, UIPosition2D gameTextPosition);
}
