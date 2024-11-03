#include "UIConstructor.h"
namespace SnakeGame
{
	void SetTextScreen(sf::Text& textScreen, std::string stringScreen, int textSize, sf::Color textColor, sf::Font& font, UIPosition2D gameTextPosition, UIPosition2D textRevelationOrigin, bool isTextBold)
	{
		textScreen.setString(stringScreen);
		textScreen.setCharacterSize(textSize);
		textScreen.setFillColor(textColor);
		textScreen.setFont(font);
		if (isTextBold)
		{
			textScreen.setStyle(sf::Text::Bold);
		}
		else
		{
			textScreen.setStyle(sf::Text::Regular);
		}
		SetTextRelativeOrigin(textScreen, textRevelationOrigin);
		textScreen.setPosition({ gameTextPosition.x, gameTextPosition.y });
	}

	void UpdateTextScreen(sf::Text& textScreen, std::string text)
	{
		textScreen.setString(text);
	}

	void UpdateTextScreen(sf::Text& textScreen, UIPosition2D gameTextPosition)
	{
		textScreen.setPosition({ gameTextPosition.x, gameTextPosition.y });
	}
}