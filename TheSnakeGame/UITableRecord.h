#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include "UIConstructor.h"
#include "Resources.h"
namespace SnakeGame
{
	class UITableRecord
	{
		std::unordered_map<std::string, int> recordsTable;
		std::multimap<int, std::string> sortedRecordsTable;
		void SortedRecordTable();
	public:
		void UpdateNumberScorePlayer(std::string namePlayerTable, int numberScore); //Adding a new player to the table or update score the old player's
		void Draw(sf::RenderWindow& window, GameResources& recources, UIPosition2D position, int numberDisplayedNames);

	};
}
