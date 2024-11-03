#pragma once
namespace sf
{
	class Text;
}

namespace SnakeGame
{
	struct UIPosition2D
	{
		float x = 0, y = 0;
	};
	
	void SetTextRelativeOrigin(sf::Text& text, const UIPosition2D& relativePosition);

}
