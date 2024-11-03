#include "UITableRecord.h"

namespace SnakeGame
{
    void UITableRecord::SortedRecordTable()
    {
        for (const auto& item : recordsTable)
        {
            sortedRecordsTable.insert(std::make_pair(item.second, item.first));
        }

    }
    void UITableRecord::UpdateNumberScorePlayer(std::string namePlayerTable, int numberScore)
    {

        recordsTable[namePlayerTable] = std::max(recordsTable[namePlayerTable],
            numberScore);

        SortedRecordTable();
    }

    void UITableRecord::Draw(sf::RenderWindow& window, GameResources& recources, UIPosition2D position, int numberDisplayedNames)
    {
        int i = 0;

        for (const auto& item : sortedRecordsTable)
        {
            if (i < numberDisplayedNames)
            {
                sf::Text textRecord;
                SetTextScreen(textRecord, (item.first + " " + item.second), 12, sf::Color::Cyan, recources.fontText, position, { 0.5f, 0.5f });
                window.draw(textRecord);
            }

            ++i;
        }
    }


}