
#include <SFML/Graphics.hpp>
#include "GameMath.h"
#include "Constants.h"
#include "Game.h"

int main()
{
	using namespace SnakeGame;
	int seed = (int)time(nullptr);
	srand(seed);


	sf::RenderWindow window(sf::VideoMode(1280, 720), "The Snake Game");

	//Game initialized
	Game game;
	game.RunApplication(game.gameStruct);
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();


	while (window.isOpen())
	{
		// Calculate time delta
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			game.UpdateEvent(event, window);

		}
		game.UpdateGame(game.gameStruct, deltaTime, window);
		window.clear();
		game.DrawGame(game.gameStruct, window);
		window.display();
	}

	return 0;
}
